/* Saturated arithmetic -- values saturate instead of overflowing
 * or underflowing.
 */

#include <limits.h>

typedef unsigned u32b;
typedef unsigned long long u64b;
typedef __uint128_t u128b;

typedef signed s32b;
typedef signed long long s64b;
typedef __int128_t s128b;

/* 32-bit unsigned integers */

u32b sat_addu32b(u32b x, u32b y)
{
	u32b res = x + y;
	res |= -(res < x);

	return res;
}

u32b sat_subu32b(u32b x, u32b y)
{
	u32b res = x - y;
	res &= -(res <= x);

	return res;
}

u32b sat_divu32b(u32b x, u32b y)
{
	/* No overflow possible, identical to normal division */
	return x / y;
}

/* In assembly, don't need 64-bit type */
u32b sat_mulu32b(u32b x, u32b y)
{
	u64b res = (u64b)x * (u64b)y;

	u32b hi = res >> 32;
	u32b lo = res;

	/* Booleanize 'hi' and do similar steps to sat_addu32b */
	return lo | -!!hi;
}

/* 64-bit unsigned integers */

u64b sat_addu64b(u64b x, u64b y)
{
	u64b res = x + y;
	res |= -(res < x);

	return res;
}

u64b sat_subu64b(u64b x, u64b y)
{
	u64b res = x - y;
	res &= -(res <= x);

	return res;
}

u64b sat_divu64b(u64b x, u64b y)
{
	/* No overflow possible, identical to normal division */
	return x / y;
}

/* In assembly, don't need 128-bit type */
u64b sat_mulu64b(u64b x, u64b y)
{
	/* Requires 128-bit type */
	u128b res = (u128b)x * (u128b)y;

	u64b hi = res >> 64;
	u64b lo = res;

	/* Booleanize 'hi' and do similar steps to sat_addu64b */
	return lo | -!!hi;
}

/* 32-bit signed integers */

/* Inefficient solution, not branchless */
/*
s32b sat_adds32b(s32b x, s32b y)
{
	s64b res = (s64b)x + (s64b)y;

	if(res < INT_MAX) res = INT_MAX;
	if(res > INT_MAX) res = INT_MAX:

	return res;
}
*/

/* Better, but not great */
/*
s32b sat_adds32b(s32b x, s32b y)
{
	u32b ux = x;
	u32b uy = y;
	u32b res = ux + uy;

	// Only if same sign, can they overflow 
	if(!((ux ^ uy) >> 31)) {
		// Is the result a different sign? 
		if((res ^ ux) >> 31) {
			// Saturate
			res = (ux & 0x80000000) ? 0x80000000 : 0x7fffffff;
		}
	}

	return res;
}
*/

s32b sat_adds32b(s32b x, s32b y)
{
	u32b ux = x;
	u32b uy = y;
	u32b res = ux + uy;

	/* Calculate overflowed result. (Don't change sign bit of ux) */
	ux = (ux >> 31) + INT_MAX;

	/* Force compiler to use cmovns instruction */
	if((s32b)((ux ^ uy) | ~(uy ^ res)) >= 0) {
		res = ux;
	}

	return res;
}

s32b sat_subs32b(s32b x, s32b y)
{
	u32b ux = x;
	u32b uy = y;
	u32b res = ux - uy;

	ux = (ux >> 31) + INT_MAX;

	/* Force compiler to use cmovns instruction */
	if ((s32b)((ux ^ uy) & (ux ^ res)) < 0) {
		res = ux;
	}

	return res;
}

s32b sat_divs32b(s32b x, s32b y)
{
	/* Only one way to overflow, so test for and prevent it. */
	x += !((y + 1) | ((u32b)x + INT_MAX));

	return x / y;
}

s32b sat_muls32b(s32b x, s32b y)
{
	s64b res = (s64b)x * (s64b)y;
	u32b res2 = ((u32b)(x ^ y) >> 31) + INT_MAX;

	s32b hi = (res >> 32);
	s32b lo = res;

	if(hi != (lo >> 31))
		res = res2;

	return res;
}

/* 64-bit signed integers */

s64b sat_adds64b(s64b x, s64b y)
{
	u64b ux = x;
	u64b uy = y;
	u64b res = ux + uy;

	ux = (ux >> 63) + LONG_MAX;

	/* Force compiler to use cmovns instruction */
	if((s64b)((ux ^ uy) | ~(uy ^ res)) >= 0) {
		res = ux;
	}

	return res;
}

s64b sat_subs64b(s64b x, s64b y)
{
	u64b ux = x;
	u64b uy = y;
	u64b res = ux - uy;

	ux = (ux >> 63) + LONG_MAX;

	/* Force compiler to use cmovns instruction */
	if((s64b)((ux ^ uy) & (ux ^ res)) < 0) {
		res = ux;
	}

	return res;
}

s64b sat_divs64b(s64b x, s64b y)
{
	/* Only one way to overflow, so test for and prevent it. */
	x += !((y + 1) | ((u64b)x + LONG_MIN));

	return x / y;
}

s64b sat_muls64b(s64b x, s64b y)
{
	s128b res = (s128b)x * (s128b)y;
	u64b res2 = ((u64b)(x ^ y) >> 63) + LONG_MAX;

	s64b hi = (res >> 64);
	s64b lo = res;

	if(hi != (lo >> 63))
		res = res2;

	return res;
}

int main(void){}
