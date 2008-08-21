//===-- CodeGen/RuntimeLibcall.h - Runtime Library Calls --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the enum representing the list of runtime library calls
// the backend may emit during code generation, and also some helper functions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CODEGEN_RUNTIMELIBCALLS_H
#define LLVM_CODEGEN_RUNTIMELIBCALLS_H

#include "llvm/CodeGen/ValueTypes.h"

namespace llvm {
namespace RTLIB {
  /// RTLIB::Libcall enum - This enum defines all of the runtime library calls
  /// the backend can emit.  The various long double types cannot be merged,
  /// because 80-bit library functions use "xf" and 128-bit use "tf".
  /// 
  /// When adding PPCF128 functions here, note that their names generally need
  /// to be overridden for Darwin with the xxx$LDBL128 form.  See
  /// PPCISelLowering.cpp.
  ///
  enum Libcall {
    // Integer
    SHL_I32,
    SHL_I64,
    SHL_I128,
    SRL_I32,
    SRL_I64,
    SRL_I128,
    SRA_I32,
    SRA_I64,
    SRA_I128,
    MUL_I32,
    MUL_I64,
    MUL_I128,
    SDIV_I32,
    SDIV_I64,
    SDIV_I128,
    UDIV_I32,
    UDIV_I64,
    UDIV_I128,
    SREM_I32,
    SREM_I64,
    SREM_I128,
    UREM_I32,
    UREM_I64,
    UREM_I128,
    NEG_I32,
    NEG_I64,

    // FLOATING POINT
    ADD_F32,
    ADD_F64,
    ADD_F80,
    ADD_PPCF128,
    SUB_F32,
    SUB_F64,
    SUB_F80,
    SUB_PPCF128,
    MUL_F32,
    MUL_F64,
    MUL_F80,
    MUL_PPCF128,
    DIV_F32,
    DIV_F64,
    DIV_F80,
    DIV_PPCF128,
    REM_F32,
    REM_F64,
    REM_F80,
    REM_PPCF128,
    POWI_F32,
    POWI_F64,
    POWI_F80,
    POWI_PPCF128,
    SQRT_F32,
    SQRT_F64,
    SQRT_F80,
    SQRT_PPCF128,
    SIN_F32,
    SIN_F64,
    SIN_F80,
    SIN_PPCF128,
    COS_F32,
    COS_F64,
    COS_F80,
    COS_PPCF128,
    POW_F32,
    POW_F64,
    POW_F80,
    POW_PPCF128,
    CEIL_F32,
    CEIL_F64,
    CEIL_F80,
    CEIL_PPCF128,
    TRUNC_F32,
    TRUNC_F64,
    TRUNC_F80,
    TRUNC_PPCF128,
    RINT_F32,
    RINT_F64,
    RINT_F80,
    RINT_PPCF128,
    NEARBYINT_F32,
    NEARBYINT_F64,
    NEARBYINT_F80,
    NEARBYINT_PPCF128,
    FLOOR_F32,
    FLOOR_F64,
    FLOOR_F80,
    FLOOR_PPCF128,

    // CONVERSION
    FPEXT_F32_F64,
    FPROUND_F64_F32,
    FPROUND_F80_F32,
    FPROUND_PPCF128_F32,
    FPROUND_F80_F64,
    FPROUND_PPCF128_F64,
    FPTOSINT_F32_I32,
    FPTOSINT_F32_I64,
    FPTOSINT_F32_I128,
    FPTOSINT_F64_I32,
    FPTOSINT_F64_I64,
    FPTOSINT_F64_I128,
    FPTOSINT_F80_I32,
    FPTOSINT_F80_I64,
    FPTOSINT_F80_I128,
    FPTOSINT_PPCF128_I32,
    FPTOSINT_PPCF128_I64,
    FPTOSINT_PPCF128_I128,
    FPTOUINT_F32_I32,
    FPTOUINT_F32_I64,
    FPTOUINT_F32_I128,
    FPTOUINT_F64_I32,
    FPTOUINT_F64_I64,
    FPTOUINT_F64_I128,
    FPTOUINT_F80_I32,
    FPTOUINT_F80_I64,
    FPTOUINT_F80_I128,
    FPTOUINT_PPCF128_I32,
    FPTOUINT_PPCF128_I64,
    FPTOUINT_PPCF128_I128,
    SINTTOFP_I32_F32,
    SINTTOFP_I32_F64,
    SINTTOFP_I32_F80,
    SINTTOFP_I32_PPCF128,
    SINTTOFP_I64_F32,
    SINTTOFP_I64_F64,
    SINTTOFP_I64_F80,
    SINTTOFP_I64_PPCF128,
    SINTTOFP_I128_F32,
    SINTTOFP_I128_F64,
    SINTTOFP_I128_F80,
    SINTTOFP_I128_PPCF128,
    UINTTOFP_I32_F32,
    UINTTOFP_I32_F64,
    UINTTOFP_I32_F80,
    UINTTOFP_I32_PPCF128,
    UINTTOFP_I64_F32,
    UINTTOFP_I64_F64,
    UINTTOFP_I64_F80,
    UINTTOFP_I64_PPCF128,
    UINTTOFP_I128_F32,
    UINTTOFP_I128_F64,
    UINTTOFP_I128_F80,
    UINTTOFP_I128_PPCF128,

    // COMPARISON
    OEQ_F32,
    OEQ_F64,
    UNE_F32,
    UNE_F64,
    OGE_F32,
    OGE_F64,
    OLT_F32,
    OLT_F64,
    OLE_F32,
    OLE_F64,
    OGT_F32,
    OGT_F64,
    UO_F32,
    UO_F64,
    O_F32,
    O_F64,

    UNKNOWN_LIBCALL
  };

  /// getFPEXT - Return the FPEXT_*_* value for the given types, or
  /// UNKNOWN_LIBCALL if there is none.
  Libcall getFPEXT(MVT OpVT, MVT RetVT);

  /// getFPROUND - Return the FPROUND_*_* value for the given types, or
  /// UNKNOWN_LIBCALL if there is none.
  Libcall getFPROUND(MVT OpVT, MVT RetVT);

  /// getFPTOSINT - Return the FPTOSINT_*_* value for the given types, or
  /// UNKNOWN_LIBCALL if there is none.
  Libcall getFPTOSINT(MVT OpVT, MVT RetVT);

  /// getFPTOUINT - Return the FPTOUINT_*_* value for the given types, or
  /// UNKNOWN_LIBCALL if there is none.
  Libcall getFPTOUINT(MVT OpVT, MVT RetVT);

  /// getSINTTOFP - Return the SINTTOFP_*_* value for the given types, or
  /// UNKNOWN_LIBCALL if there is none.
  Libcall getSINTTOFP(MVT OpVT, MVT RetVT);

  /// getUINTTOFP - Return the UINTTOFP_*_* value for the given types, or
  /// UNKNOWN_LIBCALL if there is none.
  Libcall getUINTTOFP(MVT OpVT, MVT RetVT);
}
}

#endif
