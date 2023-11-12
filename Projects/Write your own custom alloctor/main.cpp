// > We will write a ring_allocator and use it with vector STL container

// # This is a static based allocator
// # The ring is recycled automatically

// * Start with the base class

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

class ring_allocator_base {
   public:
    using size_type = std::size_t;

   protected:
    // can't be instantiated except with a derived class
    //  The rig allocator buffer size
    ring_allocator_base() {}
    //  The ring_allocator's memory allocation
    static constexpr size_type buffer_size = 64U;
    static void* do_allocate(const size_type);
};

// ! note that : the static keyword is written in the prototype only
void* ring_allocator_base::do_allocate(const size_type size) {
    // - Define the static buffer and memory pointer
    // ! Note that it is static. So, those will be executed once
    // note: we used the c-style array because STL array as they need an
    // allocator ^^
    static std::uint8_t buffer[buffer_size];
    // include where to allocate in the next operation
    static std::uint8_t* get_ptr{buffer};

    // get the newly allocated pointer
    std::uint8_t* p = get_ptr;

    get_ptr += size;  // Increment the pointer for the next allocation

    // ! Is overflow occurred?
    // - is the address get_ptr points is larger than the end address of the
    // array
    const bool is_wrap{get_ptr >= (buffer + buffer_size)};
    if(is_wrap == true) {
        p = buffer;  // currently allocate the start of the buffer

        get_ptr = buffer + size;  // next time allocate the buffer after the
                                  // size allocated in the last operation
    }
    // return the current address to allocate
    return static_cast<void*>(p);
}

// # write the ring allocator
template<class T>
struct ring_allocator : ring_allocator_base {
   public:
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef const value_type* const_pointer;
    typedef const value_type& const_reference;
    size_type max_size(void) const noexcept {
        return buffer_size / sizeof(value_type);
    }
    pointer allocate(size_type count) {
        void* p{do_allocate(count * sizeof(value_type))};
        return static_cast<pointer>(p);
    }
    void deallocate(pointer, size_type) {
        // DO NOTHING
    }
};

// > How to use this ring allocator and other allocator with STL vector
using alloc_type = ring_allocator<uint8_t>;
using response_type = std::vector<uint8_t, alloc_type>;

void login_response(response_type& rsp) {
    rsp.reserve(5U);
    rsp.push_back(UINT8_C(0x55));
    rsp.push_back(UINT8_C(0x31));
    rsp.push_back(UINT8_C(0x32));
    rsp.push_back(UINT8_C(0x33));
    std::uint8_t checksum{};

    for(const auto& i : rsp) {
        checksum += i;
    }

    rsp.push_back(checksum);
}

int main(void) {
    std::vector<std::uint8_t, alloc_type> v;
    login_response(v);
    for(const auto& i : v) {
        std::cout << i << std::endl;
    }
}
