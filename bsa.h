/* Branchfree saturating arithmetic -- values saturate instead of overflowing or
underflowing. */

#ifndef BSA_H
#define BSA_H

#include <limits.h>

/* unsigned 32-bit */

unsigned addu32(unsigned const x, unsigned const y) {
	unsigned res = x + y;
	res |= -(res < x);
	return res;
}

unsigned subu32(unsigned const x, unsigned const y) {
	unsigned res = x - y;
	res &= -(res <= x);
	return res;
}

/* no overflow possible */
unsigned divu32(unsigned const x, unsigned const y) {
	return x / y;
}

unsigned mulu32(unsigned const x, unsigned const y) {
	unsigned long const res = (unsigned long)x * (unsigned long)y;
	unsigned const hi = res >> 32;
	return res | -!!hi;
}

/* unsigned 64-bit */

unsigned long addu64(unsigned long const x, unsigned long const y) {
	unsigned long res = x + y;
	res |= -(res < x);
	return res;
}

unsigned long subu64(unsigned long const x, unsigned long const y) {
	unsigned long res = x - y;
	res &= -(res <= x);
	return res;
}

/* no overflow possible */
unsigned long divu64(unsigned long const x, unsigned long const y) {
	return x / y;
}

unsigned long mulu64(unsigned long const x, unsigned long const y) {
	__uint128_t const res = (__uint128_t)x * (__uint128_t)y;
	unsigned long const hi = res >> 64;
	return res | -!!hi;
}

/* signed 32-bit */

signed adds32(signed const x, signed const y) {
	unsigned ux = x;
	unsigned const uy = y;
	unsigned res = ux + uy;

	ux = (ux >> 31) + INT_MAX;

	/* cmovns instruction */
	if ((signed)((ux ^ uy) | ~(uy ^ res)) >= 0) {
		res = ux;
	}

	return res;
}

signed subs32(signed const x, signed const y) {
	unsigned ux = x;
	unsigned const uy = y;
	unsigned res = ux - uy;

	ux = (ux >> 31) + INT_MAX;

	/* cmovns instruction */
	if ((signed)((ux ^ uy) & (ux ^ res)) < 0) {
		res = ux;
	}

	return res;
}

signed divs32(signed x, signed const y) {
	/* only one way to overflow */
	x += !((y + 1) | ((unsigned)x + INT_MIN));
	return x / y;
}

signed muls32(signed const x, signed const y) {
	signed long res = (signed long)x * (signed long)y;
	unsigned const res2 = ((unsigned)(x ^ y) >> 31) + INT_MAX;

	signed const hi = (res >> 32);
	signed const lo = res;

	if(hi != (lo >> 31)) {
		res = res2;
	}

	return res;
}

/* signed 64-bit */

signed long adds64(signed long const x, signed long const y) {
	unsigned long ux = x;
	unsigned long const uy = y;
	unsigned long res = ux + uy;

	ux = (ux >> 63) + LONG_MAX;

	/* cmovns instruction */
	if ((signed long)((ux ^ uy) | ~(uy ^ res)) >= 0) {
		res = ux;
	}

	return res;
}

signed long subs64(signed long const x, signed long const y) {
	unsigned long ux = x;
	unsigned long const uy = y;
	unsigned long res = ux - uy;

	ux = (ux >> 63) + LONG_MAX;

	/* cmovns instruction */
	if ((signed long)((ux ^ uy) & (ux ^ res)) < 0) {
		res = ux;
	}

	return res;
}

signed long divs64(signed long x, signed long const y) {
	/* only one way to overflow */
	x += !((y + 1) | ((signed long)x + LONG_MIN));
	return x / y;
}

signed long muls64(signed long const x, signed long const y) {
	__int128_t res = (__int128_t)x * (__int128_t)y;
	unsigned long const res2 = ((unsigned long)(x ^ y) >> 63) + LONG_MAX;

	signed long const hi = (res >> 64);
	signed long const lo = res;

	if (hi != (lo >> 63)) {
		res = res2;
	}

	return res;
}

#endif /* BSA_H */
