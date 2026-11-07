#include "prx/libSceFreeType/include/Api.hpp"
#include "prx/libSceFreeType/include/GuestObjects.hpp"
#include "prx/libc/include/General.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"

#include FT_TRUETYPE_TABLES_H

#include <cstdint>

using namespace FreeType;

extern "C" {

void* APS5_VABI FT_Get_Sfnt_Table_nid_postfix(GuestFaceRec* face, std::int32_t tag) {
    const GuestFace* owner = FaceOf(face);
    void* table = FT_Get_Sfnt_Table(owner ? owner->host : nullptr, static_cast<FT_Sfnt_Tag>(tag));
    if (table && sizeof(FT_Long) != 8) NotImplemented_nid_no_patch(__func__);
    return table;
}

}
