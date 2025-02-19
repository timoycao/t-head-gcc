
(define_constants
  [(T0_REGNUM	5)
   (T1_REGNUM	6)
   (T2_REGNUM	7)
   (A0_REGNUM	10)
   (A1_REGNUM	11)
   (A2_REGNUM	12)
   (A3_REGNUM	13)
   (A4_REGNUM	14)
   (A5_REGNUM	15)
   (A6_REGNUM	16)
   (A7_REGNUM	17)
   (T3_REGNUM	28)
   (T4_REGNUM	29)
   (T5_REGNUM	30)
   (T6_REGNUM	31)
])

;; CONSTRAINT
;; ==========

(define_register_constraint "v" "TARGET_XTHEAD_VECTOR ? V_REGS : NO_REGS"
  "v0 - v31")

(define_register_constraint "u" "TARGET_XTHEAD_VECTOR ? V_NOMASK_REGS : NO_REGS"
  "v1 - v31")

(define_register_constraint "w" "TARGET_XTHEAD_VECTOR ? VMASK_REGS : NO_REGS"
  "vector mask register v0.")

(define_register_constraint "Qrf" "TARGET_XTHEAD_FMVHW32 ? FP_REGS : NO_REGS"
  "A floating-point register (if available).")

(define_register_constraint "Qrx" "TARGET_XTHEAD_FMVHW32 ? GR_REGS : NO_REGS"
  "A integer register (if available).")

(define_constraint "QcL"
  "A 6-bit unsigned immediate for zext instructions."
  (and (match_code "const_int")
       (match_test "IN_RANGE (ival, 0, 63)")))

(define_constraint "Y"
  "An I-type 3-bit signed immediate."
  (and (match_code "const_int")
       (match_test "SMALL_OPERAND_UNSIGNED3 (ival)")))

(define_constraint "Z"
  "An I-type 2-bit signed immediate."
  (and (match_code "const_int")
       (match_test "SMALL_OPERAND_UNSIGNED2 (ival)")))

(define_constraint "Pi"
  "A unsigned offset for second mem which for ldd/sdd instructions."
  (and (match_code "const_int")
       (match_test "ival >= 8 && ival <= 56")))

(define_constraint "Pj"
  "A unsigned offset for second mem which for lwd/swd instructions."
  (and (match_code "const_int")
       (match_test "ival >= 4 && ival <= 20")))

(define_constraint "Qvz"
  "@internal"
  (and (match_code "const_vector")
       (match_test "op == CONST0_RTX (mode)")))

(define_memory_constraint "Qmr"
  "@internal
   An address valid for LDR and STR instructions."
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_index_p (XEXP (op, 0), GET_MODE (op), false)")))

(define_memory_constraint "Qmu"
  "@internal
   An address valid for LDUR and STUR instructions."
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_index_p (XEXP (op, 0), GET_MODE (op), true)")))

(define_memory_constraint "Qmb"
  "@internal
   An address valid for LDIB/LDIA and STIB/STIA instructions."
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_modify_p (XEXP (op, 0), GET_MODE (op), false)")))

(define_memory_constraint "Qma"
  "@internal
   An address valid for LDIA and STIA instructions."
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_modify_p (XEXP (op, 0), GET_MODE (op), true)")))

(define_memory_constraint "Qmp"
  "@internal
   An address valid for LDD/SDD instructions."
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_pair_p (XEXP (op, 0), GET_MODE (op), true)")))

(define_memory_constraint "Qmv"
 "@internal
  An address valid for vector instructions."
 (and (match_code "mem")
      (match_test "riscv_legitimize_address_vector_p (XEXP (op, 0), GET_MODE (op))")))

;; PREDICATE
;; =========

(define_predicate "const_int_or_reg_operand"
  (ior (match_code "const_int")
       (match_operand 0 "register_operand")))

(define_predicate "const_uns16_arith_operand"
  (and (match_code "const_int")
       (match_test "SMALL_OPERAND_UNSIGNED16 (INTVAL (op))")))

(define_predicate "uns16_arith_operand"
  (ior (match_operand 0 "const_uns16_arith_operand")
       (match_operand 0 "register_operand")))

(define_predicate "const_twobit_operand"
  (and (match_code "const_int")
       (match_test "IN_RANGE (INTVAL (op), 0, 3)")))

(define_predicate "const_6bit_operand"
  (and (match_code "const_int")
       (match_test "IN_RANGE (INTVAL (op), 0, 63)")))

;; True if the operand is memory reference suitable for a load/store exclusive.
(define_predicate "riscv_sync_memory_operand"
  (and (match_operand 0 "memory_operand")
       (match_code "reg" "0")))

(define_predicate "riscv_mem_pair_operand"
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_pair_p (XEXP (op, 0), GET_MODE (op), true)")))

(define_predicate "const_Pi_operand"
  (and (match_code "const_int")
       (match_test "INTVAL (op) >= 8 && INTVAL (op) <= 56")))

(define_predicate "const_Pj_operand"
  (and (match_code "const_int")
       (match_test "INTVAL (op) >= 4 && INTVAL (op) <= 20")))

(define_predicate "fp16_less_or_equal_cmp"
  (match_code "eq,lt,le"))

(define_predicate "const_us3_operand"
  (and (match_code "const_int")
       (match_test "SMALL_OPERAND_UNSIGNED3 (INTVAL (op))")))

(define_predicate "const_us2_operand"
  (and (match_code "const_int")
       (match_test "SMALL_OPERAND_UNSIGNED2 (INTVAL (op))")))

(define_predicate "const_K_operand"
  (and (match_code "const_int")
       (match_test "INTVAL (op) >= 0 && INTVAL (op) <= 31")))

(define_predicate "const_M_operand"
  (and (match_code "const_int")
       (match_test "INTVAL (op) >= -16 && INTVAL (op) <= 15")))

(define_predicate "nonimmediate_or_0_operand"
  (ior (match_operand 0 "const_0_operand")
       (match_operand 0 "nonimmediate_operand")))

(define_predicate "vmask_mode_register_operand"
  (match_operand 0 "register_operand")
  {
     if (TARGET_XTHEAD_VLEN (64))
       return GET_MODE (op) == V8QImode;
     else if (TARGET_XTHEAD_VLEN (128))
       return GET_MODE (op) == V16QImode;
     else
       gcc_unreachable ();
  }
)

(define_predicate "riscv_vector_mem_operand"
  (and (match_code "mem")
       (match_test "riscv_legitimize_address_vector_p (XEXP (op, 0), GET_MODE (op))")))

;; MISC
;; ====

(define_constants
  [(FRM_REGNUM 106)
   (VTYPE_REGNUM 107)
])

(define_code_iterator any_bitwise_butand [ior xor])

;; Main element type used by the insn
(define_attr "emode" "unknown,QI,HI,SI,DI"
  (const_string "unknown"))

;; ADDITION
;; ========

(define_expand "adddi3"
  [(set (match_operand:DI          0 "register_operand" "=r,r")
	(plus:DI (match_operand:DI 1 "register_operand" " r,r")
		 (match_operand:DI 2 "arith_operand"    " r,I")))]
  "TARGET_64BIT || TARGET_XTHEAD_ZPSFOPERAND"
  {
    if (!TARGET_64BIT)
      operands[2] = force_reg (DImode, operands[2]);
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; SUBTRACTION
;; ===========

(define_expand "subdi3"
  [(set (match_operand:DI           0 "register_operand" "= r")
	(minus:DI (match_operand:DI 1 "reg_or_0_operand" " rj")
		  (match_operand:DI 2 "arith_operand"    "  r")))]
  "TARGET_64BIT || TARGET_XTHEAD_ZPSFOPERAND"
  {
    if (!TARGET_64BIT)
      {
	operands[1] = force_reg (DImode, operands[1]);
	operands[2] = force_reg (DImode, operands[2]);
      }
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; BIT-FIELD
;; =========

;; TARGET_XTHEAD_EXT

(define_insn "extvdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	    (sign_extract:DI (match_operand:DI 1 "register_operand" "r")
			     (match_operand 2 "const_6bit_operand" "QcL")
			     (match_operand 3 "const_6bit_operand" "QcL")))]
  "TARGET_XTHEAD_EXT && TARGET_64BIT"
  "ext\t%0,%1,%2+%3-1,%3"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "extzvdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	    (zero_extract:DI (match_operand:DI 1 "register_operand" "r")
			     (match_operand 2 "const_6bit_operand" "QcL")
			     (match_operand 3 "const_6bit_operand" "QcL")))]
  "TARGET_XTHEAD_EXT && TARGET_64BIT"
  "extu\t%0,%1,%3+%2-1,%3"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "extvsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extract:SI (match_operand:SI 1 "register_operand" "r")
			 (match_operand 2 "const_int_operand" "K")
			 (match_operand 3 "const_int_operand" "K")))]
  "TARGET_XTHEAD_EXT && !TARGET_64BIT"
  "ext\t%0,%1,%2+%3-1,%3"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "extzvsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(zero_extract:SI (match_operand:SI 1 "register_operand" "r")
			 (match_operand 2 "const_int_operand" "K")
			 (match_operand 3 "const_int_operand" "K")))]
  "TARGET_XTHEAD_EXT && !TARGET_64BIT"
  "extu\t%0,%1,%3+%2-1,%3"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*xthead_extu<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(and:X (ashift:X (match_operand:X 1 "register_operand" "r")
			 (match_operand 2 "const_int_operand" "i"))
			 (match_operand 3 "const_int_operand" "i")))]
  "TARGET_XTHEAD_EXT
   && (exact_log2 ((INTVAL (operands[3]) >> INTVAL (operands[2])) + 1) != -1)
   && ((((1 << INTVAL (operands[2])) - 1) & INTVAL (operands[3])) == 0)
   && 0"
  {
    operands[3] = GEN_INT (exact_log2 ((INTVAL (operands[3]) >> INTVAL (operands[2])) + 1)
		  - INTVAL (operands[2]));
    return "extu\t%0,%1,%3,0";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")]
)

;; LOGICAL
;; =======

;; TARGET_XTHEAD_EXT

(define_expand "anddi3"
  [(set (match_operand:DI         0 "register_operand" "")
	(and:DI (match_operand:DI 1 "register_operand" "")
		(match_operand:DI 2 "const_int_or_reg_operand" "")))]
  "TARGET_64BIT"
  "
  {
    if (CONST_INT_P (operands[2]))
      {
	if (!SMALL_OPERAND (INTVAL (operands[2])))
	  {
	    if (TARGET_64BIT && TARGET_XTHEAD_EXT)
	      {
		HOST_WIDE_INT value = INTVAL (operands[2]);
		int i;

		for (i = IMM_BITS; i <= 63; i++)
		  {
		    if (value == (((HOST_WIDE_INT)1 << i) - 1))
		      {
			emit_insn (gen_extzvdi (operands[0], operands[1],
						GEN_INT (i),
						GEN_INT (0)));
			DONE;
		      }
		  }
	      }
	    operands[2] = force_reg (DImode, operands[2]);
	  }
      }
  }
  "
)

(define_insn "*xthead_anddi3"
  [(set (match_operand:DI         0 "register_operand" "=r,r")
	(and:DI (match_operand:DI 1 "register_operand" "%r,r")
		(match_operand:DI 2 "arith_operand"    " r,I")))]
  "TARGET_64BIT"
  "and%i2\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "DI")])

(define_insn "andsi3"
  [(set (match_operand:SI         0 "register_operand" "=r,r")
	(and:SI (match_operand:SI 1 "register_operand" "%r,r")
			(match_operand:SI 2 "arith_operand"    " r,I")))]
  "!TARGET_64BIT"
  "and%i2\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "SI")])

(define_insn "*xthead_<optab>si3_sext"
  [(set (match_operand:DI              0 "register_operand" "=r,r")
	(sign_extend:DI (subreg:SI (any_bitwise:DI
	  (subreg:DI (match_operand:SI 1 "register_operand" "%r,r") 0)
	  (subreg:DI (match_operand:SI 2 "arith_operand"    " r,I") 0)) 0)))]
  "TARGET_64BIT && TARGET_XTHEAD_EXT"
  "<insn>%i2\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "SI")])

;; TARGET_XTHEAD_XOR_COMBINE

(define_insn "*xthead_xor<mode>3"
  [(set (match_operand:X        0 "register_operand" "=r,r")
	(xor:X (match_operand:X 1 "register_operand" "%r,r")
	       (match_operand:X 2 "uns16_arith_operand" "r,I")))]
  "TARGET_XTHEAD_XOR_COMBINE"
  "xor%i2\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "<MODE>")])

(define_insn "*xthead_xor<mode>3_zext"
  [(set (match_operand:X                      0 "register_operand" "=r,r")
	(xor:X (zero_extend:X
		  (subreg:HI (match_operand:X 1 "register_operand" "%r,r") 0))
	       (match_operand:X               2 "uns16_arith_operand" "r,I")))]
  "TARGET_XTHEAD_XOR_COMBINE && unsigned_reg_p (operands[1])"
  "xor%i2\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "<MODE>")])

;; ZERO EXTENSION
;; ==============

;; TARGET_XTHEAD_EXT

(define_insn "*xthead_zero_extend<mode>di2"
  [(set (match_operand:DI     0 "register_operand"    "=r")
	(zero_extend:DI
	  (match_operand:HISI 1 "register_operand"    "r")))]
  "TARGET_64BIT && TARGET_XTHEAD_EXT"
  {
    operands[2] = GEN_INT (GET_MODE_BITSIZE (<MODE>mode) - 1);
    return "extu\t%0,%1,%2,0";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*xthead_zero_extendhisi2"
  [(set (match_operand:SI     0 "register_operand"    "=r")
	(zero_extend:SI
	  (match_operand:HI 1 "register_operand"    "r")))]
  "!TARGET_64BIT && TARGET_XTHEAD_EXT"
  {
    operands[2] = GEN_INT (GET_MODE_BITSIZE (HImode) - 1);
    return "extu\t%0,%1,%2,0";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; TARGET_XTHEAD_ADDSL

(define_insn "*xthead_indexqi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))
		 (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_ADDSLUW"
  "addsluw.b\t%0, %1, %2"
  [(set_attr "type" "arith")]
)

(define_insn "*xthead_indexhi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI (and:DI (ashift:DI
		   (match_operand:DI 2 "register_operand" "r")
		   (const_int 1)) (const_int 8589934590))
		 (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_ADDSLUW"
  "addsluw.h\t%0, %1, %2"
  [(set_attr "type" "arith")]
)

(define_insn "*xthead_indexsi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI (and:DI (ashift:DI
		   (match_operand:DI 2 "register_operand" "r")
		   (const_int 2)) (const_int 17179869180))
		 (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_ADDSLUW"
  "addsluw.w\t%0, %1, %2"
  [(set_attr "type" "arith")]
)

(define_insn "*xthead_indexdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI (and:DI (ashift:DI
		   (match_operand:DI 2 "register_operand" "r")
		   (const_int 3)) (const_int 34359738360))
		 (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_ADDSLUW"
  "addsluw.d\t%0, %1, %2"
  [(set_attr "type" "arith")]
)

(define_insn "*xthead_addsl<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(plus:X (ashift:X (match_operand:X 2 "register_operand" "r")
			  (match_operand:QI 3 "const_twobit_operand" "i"))
		(match_operand:X 1 "register_operand" "r")))]
   "TARGET_XTHEAD_ADDSL"
   "addsl\t%0, %1, %2, %3"
   [(set_attr "type" "arith")]
)

(define_insn "*xthead_addsl_mult<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(plus:X (mult:X (match_operand:X 2 "register_operand" "r")
			(match_operand:X 3 "const_int_operand" "i"))
		(match_operand:X 1 "register_operand" "r")))]
   "TARGET_XTHEAD_ADDSL
    && CONST_INT_P (operands[3])
    && IN_RANGE (exact_log2 (INTVAL (operands[3])), 0, 3)"
   {
    operands[3] = gen_rtx_CONST_INT (<MODE>mode,
				     exact_log2 (INTVAL (operands[3])));
    return "addsl\t%0, %1, %2, %3";
   }
  [(set_attr "type" "arith")]
)

;; SIGN EXTENSION
;; ==============

;; TARGET_XTHEAD_EXT

(define_insn "*xthead_extend<SHORT:mode><X:mode>2"
  [(set (match_operand:X       0 "register_operand"    "=r")
	(sign_extend:X
	  (match_operand:SHORT  1 "register_operand"    "r")))]
  "TARGET_XTHEAD_EXT"
  {
    operands[2] = GEN_INT (GET_MODE_BITSIZE (<SHORT:MODE>mode) - 1);
    return "ext\t%0,%1,%2,0";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "<X:MODE>")])

;; CONDITIONAL BRANCHES
;; ====================

;; TARGET_XTHEAD_EXT

(define_insn_and_split "*xthead_branch_extend_zerocmphi"
  [(set (pc)
	(if_then_else
	 (match_operator 2 "signed_order_operator"
			 [(lshiftrt:DI (match_operand:DI 0 "register_operand" "r")
				       (match_operand:DI 1 "const_int_operand" "i"))
			  (const_int 0)])
	 (label_ref (match_operand 3 "" ""))
	 (pc)))
   (clobber (match_scratch:DI 4 "=&r"))]
  "TARGET_64BIT && TARGET_XTHEAD_EXT"
  "#"
  "reload_completed"
  [(set (match_dup 4)
	(zero_extract:DI (match_dup 0)
			 (match_operand:DI 5 "const_int_operand" "i")
			 (match_dup 1)))
   (set (pc)
	 (if_then_else
	  (match_op_dup 2 [(match_dup 4) (const_int 0)])
	  (label_ref (match_operand 3 "" ""))
	  (pc)))]
  "operands[5] = (GEN_INT (64 - INTVAL (operands[1])));"
)

(define_insn "*xthead_branch<mode>_hi"
  [(set (pc)
	(if_then_else
	 (match_operator 1 "order_operator"
			 [(sign_extend:X (subreg:HI (match_operand:SI 2 "register_operand" "r") 0))
			  (match_operand:X 3 "reg_or_0_operand" "rJ")])
	 (label_ref (match_operand 0 "" ""))
	 (pc)))]
  "TARGET_XTHEAD_C"
  "b%C1\t%2,%z3,%0"
  [(set_attr "type" "branch")
   (set_attr "mode" "none")])

;; MULTIPLY ACCUMULATION
;; =====================

;; TARGET_XTHEAD_MULA

(define_insn "*xthead_madd<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	      (plus:X (mult:X (match_operand:X 1 "register_operand" "r")
			      (match_operand:X 2 "register_operand" "r"))
		      (match_operand:X 3 "register_operand" "0")))]
  "TARGET_MUL && TARGET_XTHEAD_MULA"
  "mula\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "<MODE>")]
)

(define_insn "*xthead_msub<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	      (minus:X (match_operand:X 3 "register_operand" "0")
		       (mult:X (match_operand:X 1 "register_operand" "r")
			       (match_operand:X 2 "register_operand" "r"))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA"
  "muls\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "<MODE>")]
)

(define_insn "*xthead_maddsi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	  (plus:SI (mult:SI (match_operand:SI 1 "register_operand" "r")
			    (match_operand:SI 2 "register_operand" "r"))
		   (match_operand:SI 3 "register_operand" "0"))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA && TARGET_64BIT"
  "mulaw\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "*xthead_maddsi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	      (plus:SI (mult:SI (match_operand:SI 1 "register_operand" "r")
				(match_operand:SI 2 "register_operand" "r"))
		       (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_MUL && TARGET_XTHEAD_MULA && TARGET_64BIT"
  "mulaw\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "*xthead_msubsi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	  (minus:SI (match_operand:SI 3 "register_operand" "0")
		    (mult:SI (match_operand:SI 1 "register_operand" "r")
			     (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA && TARGET_64BIT"
  "mulsw\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "*xthead_msubsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(minus:SI (match_operand:SI 3 "register_operand" "0")
		  (mult:SI (match_operand:SI 1 "register_operand" "r")
			   (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA && TARGET_64BIT"
  "mulsw\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "maddhisi4"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (sign_extend:SI (match_operand:HI 1 "register_operand" " r"))
			  (sign_extend:SI (match_operand:HI 2 "register_operand" " r")))
		 (match_operand:SI 3 "register_operand" " 0")))]
  "TARGET_MUL && TARGET_XTHEAD_MULA"
  "mulah\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "*xthead_sextw_maddhisi4"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	  (plus:SI (mult:SI (sign_extend:SI (match_operand:HI 1 "register_operand" " r"))
			    (sign_extend:SI (match_operand:HI 2 "register_operand" " r")))
		   (match_operand:SI 3 "register_operand" " 0"))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA"
  "mulah\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "msubhisi4"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(minus:SI (match_operand:SI 3 "register_operand" " 0")
		  (mult:SI (sign_extend:SI (match_operand:HI 1 "register_operand" " r"))
			   (sign_extend:SI (match_operand:HI 2 "register_operand" " r")))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA"
  "mulsh\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

(define_insn "*xthead_sextw_msubhisi4"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	  (minus:SI (match_operand:SI 3 "register_operand" " 0")
		    (mult:SI (sign_extend:SI (match_operand:HI 1 "register_operand" " r"))
			     (sign_extend:SI (match_operand:HI 2 "register_operand" " r"))))))]
  "TARGET_MUL && TARGET_XTHEAD_MULA"
  "mulsh\\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")]
)

;; BYTE SWAP
;; =========

;; TARGET_XTHEAD_REV

(define_insn "bswapsi2"
  [(set (match_operand:SI           0 "register_operand" "=r")
	(bswap:SI (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_REVW || (TARGET_XTHEAD_REV && !TARGET_64BIT)"
  {
    return TARGET_XTHEAD_REVW ? "revw\t%0, %1" : "rev\t%0, %1";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")]
)

(define_insn "bswapdi2"
  [(set (match_operand:DI           0 "register_operand" "=r")
	(bswap:DI (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_64BIT && TARGET_XTHEAD_REV"
  "rev\t%0, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")]
)

;; SHIFTS
;; ======

;; TARGET_XTHEAD_SRRI

(define_insn "rotrsi3"
  [(set (match_operand:SI              0 "register_operand"     "=r")
	(rotatert:SI (match_operand:SI 1 "register_operand"     "r")
		     (match_operand:SI 2 "const_int_operand"    "QcL")))]
  "TARGET_XTHEAD_SRRIW || (TARGET_XTHEAD_SRRI && !TARGET_64BIT)"
  {
    return TARGET_XTHEAD_SRRIW ? "srriw\t%0, %1, %2" : "srri\t%0, %1, %2";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")]
)

(define_insn "rotrdi3"
  [(set (match_operand:DI              0 "register_operand"     "=r")
	(rotatert:DI (match_operand:DI 1 "register_operand"     "r")
		     (match_operand:DI 2 "const_int_operand"    "QcL")))]
  "TARGET_64BIT && TARGET_XTHEAD_SRRI"
  "srri\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")]
)

(define_insn "rotrsi_signext"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ior:DI (ashift:DI (match_operand:DI 1 "register_operand" "r")
			   (match_operand    2 "const_int_operand" "QcL"))
		(sign_extract:DI
		  (zero_extract:DI (match_dup 1)
				   (match_dup 2)
				   (match_operand    3 "const_int_operand" "QcL"))
		  (const_int 32)
		  (const_int 0))))]
  "TARGET_XTHEAD_SRRIW
   && ((INTVAL (operands[2]) + INTVAL (operands[3])) == 32)"
  "srriw\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")]
)

(define_insn_and_split "*xthead_rotrsi_zeroext"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ior:DI (ashift:DI (match_operand:DI 1 "register_operand" "r")
			   (match_operand    2 "const_int_operand" "QcL"))
		(zero_extract:DI (match_dup 1)
				 (match_dup 2)
				 (match_operand    3 "const_int_operand" "QcL"))))]
  "TARGET_XTHEAD_SRRIW
   && ((INTVAL (operands[2]) + INTVAL (operands[3])) == 32)"
  "#"
  "&& true"
  [(const_int 0)]
  {
    emit_insn (gen_rotrsi_signext (operands[0], operands[1], operands[2],
				   operands[3]));
    emit_insn (gen_extzvdi (operands[0], operands[0], GEN_INT (32), GEN_INT (0)));
    DONE;
  }
)

;; CONDITIONAL MOVE
;; ================

;; TARGET_XTHEAD_CONDMV

;; TODO This cannot be generated unless the operand 1 has no mode,
;;      but it will increase the dynamic instruction count in case
;;      of GCC-1367
(define_expand "mov<GPR:mode>cc"
  [(set (match_operand:GPR 0 "register_operand" "")
	(if_then_else:GPR (match_operand:DI 1 "order_operator" "")
			  (match_operand:GPR 2 "reg_or_0_operand" "")
			  (match_operand:GPR 3 "register_operand" "")))]
  "TARGET_XTHEAD_CONDMV && !optimize_size"
{
  int result = riscv_expand_movcc (operands);
  switch (result)
    {
    case 0:
      DONE;
      break;
    case -1:
      FAIL;
      break;
    case 1:
      break;
    default:
      gcc_unreachable ();
    }
})

(define_insn_and_split "*xthead_cmov<GPR:mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(if_then_else:GPR (match_operator 1 "order_operator"
			     [(match_operand:X 2 "register_operand" "r")
			      (match_operand:X 3 "register_operand" "r")])
			  (match_operand:GPR 4 "reg_or_0_operand" "rJ")
			  (match_operand:GPR 5 "register_operand" "r")))]
  "TARGET_XTHEAD_CONDMV
   && !reload_completed"
  "#"
  "&& true"
  [(const_int 0)]
  {
    emit_insn (gen_mov<GPR:mode>cc (operands[0], operands[1],
				    operands[4], operands[5]));
    DONE;
  }
)

(define_insn "*xthead_cmovz<GPR:mode>"
  [(set (match_operand:GPR 0 "register_operand"                     "=r, r")
	(if_then_else:GPR (eq (match_operand:X 1 "register_operand" " r, r")
			      (const_int 0))
			  (match_operand:GPR 2 "reg_or_0_operand"    "rJ, 0")
			  (match_operand:GPR 3 "register_operand"    " 0, r")))]
  "TARGET_XTHEAD_CONDMV"
  "@
   mveqz\t%0, %z2, %1
   mvnez\t%0, %3, %1"
  [(set_attr "type" "arith")]
)

(define_insn "*xthead_cmovn<GPR:mode>"
  [(set (match_operand:GPR 0 "register_operand"                         "=r, r")
	    (if_then_else:GPR (ne (match_operand:X 1 "register_operand" " r, r")
				  (const_int 0))
			      (match_operand:GPR 2 "reg_or_0_operand"   "rJ, 0")
			      (match_operand:GPR 3 "register_operand"   " 0, r")))]
  "TARGET_XTHEAD_CONDMV"
  "@
   mvnez\t%0, %z2, %1
   mveqz\t%0, %3, %1"
  [(set_attr "type" "arith")]
)

;; MISC
;; ====

;; TARGET_XTHEAD_LDD

;; double store
(define_peephole2
  [(set (match_operand:DI 0 "riscv_mem_pair_operand" "")
	(match_operand:DI 1 "register_operand" ""))
   (set (match_operand:DI 2 "memory_operand" "")
	(match_operand:DI 3 "register_operand" ""))]
  "TARGET_XTHEAD_LDD
  && rtx_equal_p (XEXP (operands[2], 0),
      plus_constant (Pmode, XEXP (operands[0], 0), GET_MODE_SIZE (DImode)))
  && GET_CODE (XEXP (operands[2], 0)) == PLUS
  && (INTVAL (XEXP (XEXP (operands[2], 0), 1)) - 8) <= 48
  && (INTVAL (XEXP (XEXP (operands[2], 0), 1)) - 8) >= 0"
  [(parallel [(set (match_dup 0) (match_dup 1))
	      (set (match_dup 2) (match_dup 3))])]
)

(define_peephole2
  [(set (match_operand:SI 0 "riscv_mem_pair_operand" "")
	(match_operand:SI 1 "register_operand" ""))
   (set (match_operand:SI 2 "memory_operand" "")
	(match_operand:SI 3 "register_operand" ""))]
  "TARGET_XTHEAD_LDD
  && rtx_equal_p (XEXP (operands[2], 0),
      plus_constant (Pmode, XEXP (operands[0], 0), GET_MODE_SIZE (SImode)))
  && GET_CODE (XEXP (operands[2], 0)) == PLUS
  && (INTVAL (XEXP (XEXP (operands[2], 0), 1)) - 4) <= 16
  && (INTVAL (XEXP (XEXP (operands[2], 0), 1)) - 4) >= 0"
  [(parallel [(set (match_dup 0) (match_dup 1))
	      (set (match_dup 2) (match_dup 3))])]
)

;; SDD
(define_insn "store_pairdi"
  [(set (match_operand:DI 0 "riscv_mem_pair_operand" "=Qmp")
	(match_operand:DI 1 "register_operand"       "r"))
   (set (mem:DI (plus:DI (match_operand:DI 2 "register_operand"      "r")
			 (match_operand  3 "const_Pi_operand"     "Pi")))
	(match_operand:DI 4 "register_operand"       "r"))]
  "TARGET_XTHEAD_LDD
   && rtx_equal_p (plus_constant (Pmode, operands[2], INTVAL (operands[3])),
      plus_constant (Pmode, XEXP (operands[0], 0), GET_MODE_SIZE (DImode)))"
  "sdd\t%1,%4,(%2),%j3,4"
  [(set_attr "type" "store")
   (set_attr "mode" "DI")])

;; SWD
(define_insn "*store_pairsi<mode>"
  [(set (match_operand:SI 0 "riscv_mem_pair_operand" "=Qmp")
	(match_operand:SI 1 "register_operand"       "r"))
   (set (mem:SI (plus:X (match_operand:X 2 "register_operand"      "r")
			 (match_operand 3 "const_Pj_operand"     "Pj")))
	(match_operand:SI 4 "register_operand"       "r"))]
  "TARGET_XTHEAD_LDD
  && rtx_equal_p (plus_constant (Pmode, operands[2], INTVAL (operands[3])),
      plus_constant (Pmode, XEXP (operands[0], 0), GET_MODE_SIZE (SImode)))"
  "swd\t%1,%4,(%2),%k3,3"
  [(set_attr "type" "store")
   (set_attr "mode" "SI")])

;; double load
(define_peephole2
  [(set (match_operand:DI 0 "register_operand" "")
	(match_operand:DI 1 "riscv_mem_pair_operand" ""))
   (set (match_operand:DI 2 "register_operand" "")
	(match_operand:DI 3 "memory_operand" ""))]
  "TARGET_XTHEAD_LDD
  && REGNO (operands[0]) != REGNO (operands[2])
  && rtx_equal_p (XEXP (operands[3], 0),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (DImode)))
  && GET_CODE (XEXP (operands[3], 0)) == PLUS
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 8) <= 48
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 8) >= 0
  && REGNO (operands[0]) != REGNO (XEXP (XEXP (operands[3], 0), 0))
  && REGNO (operands[2]) != REGNO (XEXP (XEXP (operands[3], 0), 0))"
  [(parallel [(set (match_dup 0) (match_dup 1))
	      (set (match_dup 2) (match_dup 3))])]
)

(define_peephole2
  [(set (match_operand:DI 0 "register_operand" "")
	(sign_extend:DI (match_operand:SI 1 "riscv_mem_pair_operand" "")))
   (set (match_operand:DI 2 "register_operand" "")
	(sign_extend:DI (match_operand:SI 3 "memory_operand" "")))]
  "TARGET_XTHEAD_LDD
  && REGNO (operands[0]) != REGNO (operands[2])
  && rtx_equal_p (XEXP (operands[3], 0),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (SImode)))
  && GET_CODE (XEXP (operands[3], 0)) == PLUS
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 4) <= 16
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 4) >= 0
  && REGNO (operands[0]) != REGNO (XEXP (XEXP (operands[3], 0), 0))
  && REGNO (operands[2]) != REGNO (XEXP (XEXP (operands[3], 0), 0))"
  [(parallel [(set (match_dup 0) (sign_extend:DI (match_dup 1)))
	      (set (match_dup 2) (sign_extend:DI (match_dup 3)))])]
)

(define_peephole2
  [(set (match_operand:DI 0 "register_operand" "")
	(zero_extend:DI (match_operand:SI 1 "riscv_mem_pair_operand" "")))
   (set (match_operand:DI 2 "register_operand" "")
	(zero_extend:DI (match_operand:SI 3 "memory_operand" "")))]
  "TARGET_XTHEAD_LDD
  && REGNO (operands[0]) != REGNO (operands[2])
  && rtx_equal_p (XEXP (operands[3], 0),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (SImode)))
  && GET_CODE (XEXP (operands[3], 0)) == PLUS
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 4) <= 16
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 4) >= 0
  && REGNO (operands[0]) != REGNO (XEXP (XEXP (operands[3], 0), 0))
  && REGNO (operands[2]) != REGNO (XEXP (XEXP (operands[3], 0), 0))"
  [(parallel [(set (match_dup 0) (zero_extend:DI (match_dup 1)))
	      (set (match_dup 2) (zero_extend:DI (match_dup 3)))])]
)

(define_peephole2
  [(set (match_operand:SI 0 "register_operand" "")
	(match_operand:SI 1 "riscv_mem_pair_operand" ""))
   (set (match_operand:SI 2 "register_operand" "")
	(match_operand:SI 3 "memory_operand" ""))]
  "!TARGET_64BIT && TARGET_XTHEAD_LDD
  && REGNO (operands[0]) != REGNO (operands[2])
  && rtx_equal_p (XEXP (operands[3], 0),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (SImode)))
  && GET_CODE (XEXP (operands[3], 0)) == PLUS
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 4) <= 16
  && (INTVAL (XEXP (XEXP (operands[3], 0), 1)) - 4) >= 0
  && REGNO (operands[0]) != REGNO (XEXP (XEXP (operands[3], 0), 0))
  && REGNO (operands[2]) != REGNO (XEXP (XEXP (operands[3], 0), 0))"
  [(parallel [(set (match_dup 0) (match_dup 1))
	      (set (match_dup 2) (match_dup 3))])]
)

;; LDD
(define_insn "load_pairdi"
  [(set (match_operand:DI 0 "register_operand"        "=r")
	(match_operand:DI 1 "riscv_mem_pair_operand"  "Qmp"))
   (set (match_operand:DI 2 "register_operand"        "=r")
	(mem:DI (plus:DI (match_operand:DI 3 "register_operand"      "r")
			 (match_operand  4 "const_Pi_operand"     "Pi"))))]
  "TARGET_XTHEAD_LDD
  && rtx_equal_p (plus_constant (Pmode, operands[3], INTVAL (operands[4])),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (DImode)))
  && REGNO (operands[0]) != REGNO (operands[3])
  && REGNO (operands[2]) != REGNO (operands[3])"
  "ldd\t%0,%2,(%3),%j4,4"
  [(set_attr "type" "load")
   (set_attr "mode" "DI")])

;; LWD
(define_insn "*load_pair_extendsidi"
  [(set (match_operand:DI 0 "register_operand"        "=r")
	(sign_extend:DI (match_operand:SI 1 "riscv_mem_pair_operand"  "Qmp")))
   (set (match_operand:DI 2 "register_operand"        "=r")
	(sign_extend:DI (mem:SI (plus:DI (match_operand:DI 3 "register_operand"      "r")
					 (match_operand 4 "const_Pj_operand"     "Pj")))))]
  "TARGET_XTHEAD_LDD
   && rtx_equal_p (plus_constant (Pmode, operands[3], INTVAL (operands[4])),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (SImode)))
   && REGNO (operands[0]) != REGNO (operands[3])
   && REGNO (operands[2]) != REGNO (operands[3])"
  "lwd\t%0,%2,(%3),%k4,3"
  [(set_attr "type" "load")
   (set_attr "mode" "SI")])

(define_insn "load_pairsi"
  [(set (match_operand:SI 0 "register_operand"        "=r")
	(match_operand:SI 1 "riscv_mem_pair_operand"  "Qmp"))
   (set (match_operand:SI 2 "register_operand"        "=r")
	(mem:SI (plus:SI (match_operand:SI 3 "register_operand"      "r")
			 (match_operand 4 "const_Pj_operand"     "Pj"))))]
  "!TARGET_64BIT && TARGET_XTHEAD_LDD
   && rtx_equal_p (plus_constant (Pmode, operands[3], INTVAL (operands[4])),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (SImode)))
   && REGNO (operands[0]) != REGNO (operands[3])
   && REGNO (operands[2]) != REGNO (operands[3])"
  "lwd\t%0,%2,(%3),%k4,3"
  [(set_attr "type" "load")
   (set_attr "mode" "SI")])

;; LWUD
(define_insn "*load_pair_zero_extendsidi"
  [(set (match_operand:DI 0 "register_operand"        "=r")
	(zero_extend:DI (match_operand:SI 1 "riscv_mem_pair_operand"  "Qmp")))
   (set (match_operand:DI 2 "register_operand"        "=r")
	(zero_extend:DI (mem:SI (plus:DI (match_operand:DI 3 "register_operand"      "r")
					 (match_operand  4 "const_Pj_operand"     "Pj")))))]
  "TARGET_XTHEAD_LDD
   && rtx_equal_p (plus_constant (Pmode, operands[3], INTVAL (operands[4])),
      plus_constant (Pmode, XEXP (operands[1], 0), GET_MODE_SIZE (SImode)))
  && REGNO (operands[0]) != REGNO (operands[3])
  && REGNO (operands[2]) != REGNO (operands[3])"
  "lwud\t%0,%2,(%3),%k4,3"
  [(set_attr "type" "load")
   (set_attr "mode" "SI")])

;; Builtins
;; ========

(define_c_enum "unspecv" [
  ;; Floating-point unspecs.
  UNSPECV_FRRM
  UNSPECV_FSRM
  ;; Interrupt handler instructions.
  UNSPECV_IPUSH
  UNSPECV_IPOP
])

(define_insn "riscv_frrm"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile [(const_int 0)] UNSPECV_FRRM))]
  "TARGET_HARD_FLOAT"
  "frrm\t%0"
)

(define_insn "riscv_fsrm"
  [(set (reg:SI FRM_REGNUM)
	(unspec_volatile [(match_operand:SI 0 "csr_operand" "r,K")] UNSPECV_FSRM))]
  "TARGET_HARD_FLOAT"
  "@
   fsrm\t%0
   fsrmi\t%0"
)

;; TARGET_XTHEAD_IPUSH

(define_insn "riscv_ipop"
  [(return)
   (unspec_volatile [(const_int 0)] UNSPECV_IPOP)]
  "TARGET_XTHEAD_IPUSH"
  "ipop")

(define_insn "riscv_ipush"
  [(unspec_volatile [(const_int 0)] UNSPECV_IPUSH)
   (use (reg RETURN_ADDR_REGNUM))
   (use (reg T0_REGNUM))
   (use (reg T1_REGNUM))
   (use (reg T2_REGNUM))
   (use (reg A0_REGNUM))
   (use (reg A1_REGNUM))
   (use (reg A2_REGNUM))
   (use (reg A3_REGNUM))
   (use (reg A4_REGNUM))
   (use (reg A5_REGNUM))
   (use (reg A6_REGNUM))
   (use (reg A7_REGNUM))
   (use (reg T3_REGNUM))
   (use (reg T4_REGNUM))
   (use (reg T5_REGNUM))
   (use (reg T6_REGNUM))]
  "TARGET_XTHEAD_IPUSH"
  "ipush")

(include "c906.md")
(include "c910.md")
