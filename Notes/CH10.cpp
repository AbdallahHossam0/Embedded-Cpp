// > CH10 : Custom Memory Management

// To allocate memory in C++ you can use "new" operator
// it returns nullptr or throws std::bad_alloc exception depending of which new
// version we use.

// to dealloc[free] memory we use delete operator

// new and delete operator are usually use the free store [heap] memory section

// * please note:
// you can overload the global new and delete operator

// in Embedded Systems programming using dynamic allocation is not a good idea.

// ! fragmentation is one of the main reason that limits using dynamic
// ! allocation on Embedded Systems

// there is another version of new operator called placement-new
// that allows programmers to control where to allocate memory [physical
// address]

void* operator new(size_t, void*) noexcept;

// # Properties
// 1- unable to throw exceptions (no mem -> return nullptr)
// 2- first param -> size of the object in  bytes
// 3- second param -> where to place that object[physically]
// 4- using placement-new requires explicit call for the destructor [~object()]

// * To use it you should include placement-new operator by include <new>
// * create where to allocate memory to this object by void* mem {address};
// * call new
// -> T* ob = new(mem) T(args);
// * To delete it use
// -> ~ob(); or ob->~T();

// # Great Example

class ob {
   public:
    void doMyThing(void) {}
    ~ob(){};
};

void doSomething(void) {
    chars pool[sizeof(ob)];
    ob* T{new(pool) ob};
    T->doMyThing();
    T->~ob();  // explicitly call the destructor
}

// this new object is created on the stack not in the heap -> I create an array
// of chars with size of the object then I allocate this ob in the address of
// pool

// this object will stored in the stack and then it will be deleted
// automatically (No need to use delete) but you need to explicitly call the
// destructor

// ! No delete with placement new ^^

// * STL containers have a template parameter which is called {Allocator Type}
// * Remember that -> Placement-new solve the problem of fragmentation
// * To use STL in micro controller programming you should replace this default
// *  allocator with specialized custom allocator
// * you should rely on using placement-new in your custom allocator

// # To use vector STL with your allocator you should do that

vector<int, allocator<int>> vec(3U);
