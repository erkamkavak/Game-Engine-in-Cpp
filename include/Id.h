#include "CommonHeaders.h"


namespace brix::id {
    using id_type = u32; 
    constexpr u32 generation_bits{8};
    constexpr u32 index_bits{sizeof(id_type) * 8 - generation_bits};  
    constexpr id_type index_mask{ (id_type{1} << index_bits) - 1 }; // 0111 for 4 bit  
    constexpr id_type generation_mask { (id_type{1} << generation_bits) - 1};
    constexpr id_type id_mask{ id_type{-1} }; // it is the same as id_type{1} << size(id_type) - 1
     
}