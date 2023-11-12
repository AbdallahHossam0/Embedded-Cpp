// > Write your Custom Allocator

// ? What allocator is?
// - The basic purpose of allocator is to provide a source of memory for a given
// type, and a place  to return that memory to once it is no longer needed

// - A service that grants exclusive use of a region of memory to a client

// ? Why we need allocator?
// - We need it to provide an interface that is more granular than new and
// delete operators

// ? Why to write your own allocator?
// - Higher performance => stack-based allocator - Per-thread allocation
// - Debug, test and instrument
// - Relocatable data => Shared memory

// * To use custom allocator with STL Container, you must adhere to the
// * interface of the standard allocator std::allocator<T>

// # Standard Allocator Interface
namespace std {
    template<class T>
    class allocator {
       public:
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef value_type* pointer;
        typedef value_type& reference;
        typedef const value_type* const_pointer;
        typedef const value_type& const_reference;

        allocator() noexcept;
        allocator(const allocator&) noexcept;  // copy constructor

        template<class U>
        allocator(
            const allocator<U>&) noexcept;  // copy constructor of another type

        ~allocator();

        template<class U>
        struct rebind {
            typedef allocator<U> other;
        };

        size_type max_size() const noexcept;
        pointer address(reference) const;
        pointer allocate(size_type,
                         typename allocator<void>::const_pointer = nullptr);
        void construct(pointer, const value_type&);
        void destroy(pointer);
        void deallocate(pointer, size_type);
    };
};  // namespace std
