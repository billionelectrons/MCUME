#include "shared.h"

#include "machdep/m68k.h"
#include "memory.h"
#include "custom.h"
#include "readcpu.h"
#include "newcpu.h"
#include "compiler.h"
#include "cputbl.h"
#if !defined (MEMFUNCS_DIRECT_REQUESTED) || defined (DIRECT_MEMFUNCS_SUCCESSFUL)
void REGPARAM2 CPU_OP_NAME(_e000)(uae_u32 opcode) /* ASR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	uae_u32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		val = sign ? 0xff : 0;
		CFLG=XFLG= sign ? 1 : 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
		if (sign) val |= 0xff << (8 - cnt);
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e008)(uae_u32 opcode) /* LSR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		CFLG=XFLG = cnt == 8 ? (val & cmask ? 1 : 0) : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e010)(uae_u32 opcode) /* ROXR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e018)(uae_u32 opcode) /* ROR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&1; val = val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e020)(uae_u32 opcode) /* ASR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	uae_u32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		val = sign ? 0xff : 0;
		CFLG=XFLG= sign ? 1 : 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
		if (sign) val |= 0xff << (8 - cnt);
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e028)(uae_u32 opcode) /* LSR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		CFLG=XFLG = cnt == 8 ? (val & cmask ? 1 : 0) : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e030)(uae_u32 opcode) /* ROXR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e038)(uae_u32 opcode) /* ROR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&1; val = val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e040)(uae_u32 opcode) /* ASR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		val = sign ? 0xffff : 0;
		CFLG=XFLG= sign ? 1 : 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
		if (sign) val |= 0xffff << (16 - cnt);
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e048)(uae_u32 opcode) /* LSR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		CFLG=XFLG = cnt == 16 ? (val & cmask ? 1 : 0) : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e050)(uae_u32 opcode) /* ROXR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e058)(uae_u32 opcode) /* ROR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&1; val = val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e060)(uae_u32 opcode) /* ASR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		val = sign ? 0xffff : 0;
		CFLG=XFLG= sign ? 1 : 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
		if (sign) val |= 0xffff << (16 - cnt);
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e068)(uae_u32 opcode) /* LSR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		CFLG=XFLG = cnt == 16 ? (val & cmask ? 1 : 0) : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e070)(uae_u32 opcode) /* ROXR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e078)(uae_u32 opcode) /* ROR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&1; val = val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e080)(uae_u32 opcode) /* ASR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	uae_u32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		val = sign ? 0xffffffff : 0;
		CFLG=XFLG= sign ? 1 : 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
		if (sign) val |= 0xffffffff << (32 - cnt);
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e088)(uae_u32 opcode) /* LSR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		CFLG=XFLG = cnt == 32 ? (val & cmask ? 1 : 0) : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e090)(uae_u32 opcode) /* ROXR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e098)(uae_u32 opcode) /* ROR */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&1; val = val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0a0)(uae_u32 opcode) /* ASR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	uae_u32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		val = sign ? 0xffffffff : 0;
		CFLG=XFLG= sign ? 1 : 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
		if (sign) val |= 0xffffffff << (32 - cnt);
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0a8)(uae_u32 opcode) /* LSR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		CFLG=XFLG = cnt == 32 ? (val & cmask ? 1 : 0) : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val >> (cnt-1)) & 1;
		val >>= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0b0)(uae_u32 opcode) /* ROXR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0b8)(uae_u32 opcode) /* ROR */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&1; val = val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0d0)(uae_u32 opcode) /* ASRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e0d8)(uae_u32 opcode) /* ASRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0e0)(uae_u32 opcode) /* ASRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0e8)(uae_u32 opcode) /* ASRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e0f0)(uae_u32 opcode) /* ASRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e0f8)(uae_u32 opcode) /* ASRW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e0f9)(uae_u32 opcode) /* ASRW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e100)(uae_u32 opcode) /* ASL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		VFLG = val != 0;
		CFLG=XFLG = cnt == 8 ? val & 1 : 0;
		val = 0;
	} else {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		VFLG = (val & mask) != mask && (val & mask) != 0;
		val <<= cnt;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e108)(uae_u32 opcode) /* LSL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		CFLG=XFLG = cnt == 8 ? val & 1 : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		val <<= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e110)(uae_u32 opcode) /* ROXL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e118)(uae_u32 opcode) /* ROL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry) val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e120)(uae_u32 opcode) /* ASL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		VFLG = val != 0;
		CFLG=XFLG = cnt == 8 ? val & 1 : 0;
		val = 0;
	} else {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		VFLG = (val & mask) != mask && (val & mask) != 0;
		val <<= cnt;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e128)(uae_u32 opcode) /* LSL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 8) {
		CFLG=XFLG = cnt == 8 ? val & 1 : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		val <<= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e130)(uae_u32 opcode) /* ROXL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e138)(uae_u32 opcode) /* ROL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u8 val = data;
	uae_u32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry) val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e140)(uae_u32 opcode) /* ASL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		VFLG = val != 0;
		CFLG=XFLG = cnt == 16 ? val & 1 : 0;
		val = 0;
	} else {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		VFLG = (val & mask) != mask && (val & mask) != 0;
		val <<= cnt;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e148)(uae_u32 opcode) /* LSL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		CFLG=XFLG = cnt == 16 ? val & 1 : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		val <<= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e150)(uae_u32 opcode) /* ROXL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e158)(uae_u32 opcode) /* ROL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry) val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e160)(uae_u32 opcode) /* ASL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		VFLG = val != 0;
		CFLG=XFLG = cnt == 16 ? val & 1 : 0;
		val = 0;
	} else {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		VFLG = (val & mask) != mask && (val & mask) != 0;
		val <<= cnt;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e168)(uae_u32 opcode) /* LSL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 16) {
		CFLG=XFLG = cnt == 16 ? val & 1 : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		val <<= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e170)(uae_u32 opcode) /* ROXL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e178)(uae_u32 opcode) /* ROL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry) val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e180)(uae_u32 opcode) /* ASL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		VFLG = val != 0;
		CFLG=XFLG = cnt == 32 ? val & 1 : 0;
		val = 0;
	} else {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		VFLG = (val & mask) != mask && (val & mask) != 0;
		val <<= cnt;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e188)(uae_u32 opcode) /* LSL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		CFLG=XFLG = cnt == 32 ? val & 1 : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		val <<= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e190)(uae_u32 opcode) /* ROXL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e198)(uae_u32 opcode) /* ROL */
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry) val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1a0)(uae_u32 opcode) /* ASL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		VFLG = val != 0;
		CFLG=XFLG = cnt == 32 ? val & 1 : 0;
		val = 0;
	} else {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		VFLG = (val & mask) != mask && (val & mask) != 0;
		val <<= cnt;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1a8)(uae_u32 opcode) /* LSL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	if (cnt >= 32) {
		CFLG=XFLG = cnt == 32 ? val & 1 : 0;
		val = 0;
	} else {
		CFLG=XFLG=(val << (cnt-1)) & cmask ? 1 : 0;
		val <<= cnt;
	}}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1b0)(uae_u32 opcode) /* ROXL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	uae_u32 carry;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	}
	CFLG = XFLG;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1b8)(uae_u32 opcode) /* ROL */
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {
	uae_u32 carry;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry) val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	m68k_dreg(regs, dstreg) = (val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1d0)(uae_u32 opcode) /* ASLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e1d8)(uae_u32 opcode) /* ASLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1e0)(uae_u32 opcode) /* ASLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1e8)(uae_u32 opcode) /* ASLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e1f0)(uae_u32 opcode) /* ASLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e1f8)(uae_u32 opcode) /* ASLW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e1f9)(uae_u32 opcode) /* ASLW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
	VFLG = 0;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 sign = cmask & val;
	CFLG=XFLG=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e2d0)(uae_u32 opcode) /* LSRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e2d8)(uae_u32 opcode) /* LSRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e2e0)(uae_u32 opcode) /* LSRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e2e8)(uae_u32 opcode) /* LSRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e2f0)(uae_u32 opcode) /* LSRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e2f8)(uae_u32 opcode) /* LSRW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e2f9)(uae_u32 opcode) /* LSRW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e3d0)(uae_u32 opcode) /* LSLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e3d8)(uae_u32 opcode) /* LSLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e3e0)(uae_u32 opcode) /* LSLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e3e8)(uae_u32 opcode) /* LSLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e3f0)(uae_u32 opcode) /* LSLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e3f8)(uae_u32 opcode) /* LSLW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e3f9)(uae_u32 opcode) /* LSLW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = XFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e4d0)(uae_u32 opcode) /* ROXRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e4d8)(uae_u32 opcode) /* ROXRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e4e0)(uae_u32 opcode) /* ROXRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e4e8)(uae_u32 opcode) /* ROXRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e4f0)(uae_u32 opcode) /* ROXRW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e4f8)(uae_u32 opcode) /* ROXRW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e4f9)(uae_u32 opcode) /* ROXRW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(XFLG) val |= cmask;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e5d0)(uae_u32 opcode) /* ROXLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e5d8)(uae_u32 opcode) /* ROXLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e5e0)(uae_u32 opcode) /* ROXLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e5e8)(uae_u32 opcode) /* ROXLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e5f0)(uae_u32 opcode) /* ROXLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e5f8)(uae_u32 opcode) /* ROXLW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e5f9)(uae_u32 opcode) /* ROXLW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(XFLG) val |= 1;
	XFLG = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
XFLG = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e6d0)(uae_u32 opcode) /* RORW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e6d8)(uae_u32 opcode) /* RORW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e6e0)(uae_u32 opcode) /* RORW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e6e8)(uae_u32 opcode) /* RORW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e6f0)(uae_u32 opcode) /* RORW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e6f8)(uae_u32 opcode) /* RORW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e6f9)(uae_u32 opcode) /* RORW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val&1;
	uae_u32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e7d0)(uae_u32 opcode) /* ROLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e7d8)(uae_u32 opcode) /* ROLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e7e0)(uae_u32 opcode) /* ROLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	m68k_areg(regs, srcreg) -= 2;
{	uaecptr dataa = m68k_areg(regs, srcreg);
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e7e8)(uae_u32 opcode) /* ROLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e7f0)(uae_u32 opcode) /* ROLW */
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = get_disp_ea(m68k_areg(regs, srcreg));
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void REGPARAM2 CPU_OP_NAME(_e7f8)(uae_u32 opcode) /* ROLW */
{
{{	uaecptr dataa = (uae_s32)(uae_s16)nextiword();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void REGPARAM2 CPU_OP_NAME(_e7f9)(uae_u32 opcode) /* ROLW */
{
{{	uaecptr dataa = nextilong();
	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 cmask = 0x8000;
	uae_u32 carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((uae_s16)(val)) == 0;
	NFLG = ((uae_s16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
#endif
