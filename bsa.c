#include <stdint.h>

#define ADDU(N)\
uint##N##_t addu##N(uint##N##_t const x, uint##N##_t const y)\
{\
	uint##N##_t res = (uint##N##_t)(x + y);\
	res |= (uint##N##_t)(-(res < x));\
	return res;\
}

#define SUBU(N)\
uint##N##_t subu##N(uint##N##_t const x, uint##N##_t const y)\
{\
	uint##N##_t res = (uint##N##_t)(x - y);\
	res &= (uint##N##_t)(-(res < x));\
	return res;\
}

#define DIVU(N)\
uint##N##_t divu##N(uint##N##_t const x, uint##N##_t const y)\
{\
	return x / y;\
}

#define MULU(N, M)\
uint##N##_t mulu##N(uint##N##_t const x, uint##N##_t const y)\
{\
	uint##M##_t const res = (uint##M##_t)((uint##M##_t)x * (uint##M##_t)y);\
	uint##N##_t const hi = (uint##N##_t)(res >> N);\
	return (uint##N##_t)(res | (uint##M##_t)(-!!hi));\
}

#define ADDS(N)\
int##N##_t adds##N(int##N##_t const x, int##N##_t const y)\
{\
	uint##N##_t ux = (uint##N##_t)x;\
	uint##N##_t const uy = (uint##N##_t)y;\
	uint##N##_t res = (uint##N##_t)(ux + uy);\
	ux = (uint##N##_t)((ux >> (N - 1)) + INT##N##_MAX);\
	/* cmovns instruction */\
	if ((int##N##_t)((ux ^ uy) | ~(uy ^ res)) >= 0) {\
		res = ux;\
	}\
	return (int##N##_t)res;\
}

#define SUBS(N)\
int##N##_t subs##N(int##N##_t const x, int##N##_t const y)\
{\
	uint##N##_t ux = (uint##N##_t)x;\
	uint##N##_t const uy = (uint##N##_t)y;\
	uint##N##_t res = (uint##N##_t)(ux - uy);\
	ux = (uint##N##_t)((ux >> (N - 1)) + INT##N##_MAX);\
	if ((int##N##_t) ((ux ^ uy) & (ux ^ res)) < 0) {\
		res = ux;\
	}\
	return (int##N##_t)res;\
}

#define DIVS(N)\
int##N##_t divs##N(int##N##_t const x, int##N##_t const y)\
{\
	int##N##_t const n = (int##N##_t)(x + !((uint##N##_t)(y + 1) | (uint##N##_t)(x + INT##N##_MIN)));\
	return (int##N##_t)(n / y);\
}

#define MULS(N, M)\
int##N##_t muls##N(int##N##_t const x, int##N##_t const y)\
{\
	int##M##_t res = (int##M##_t)((int##M##_t)x * (int##M##_t)y);\
	uint##N##_t const res2 = (uint##N##_t)((((uint##N##_t)x ^ (uint##N##_t)y) >> (N - 1)) + INT##N##_MAX);\
	int##N##_t const hi = (int##N##_t)(res >> N);\
	int##N##_t const lo = (int##N##_t)res;\
	if (hi != (lo >> (N-1))) {\
		res = (int##M##_t)res2;\
	}\
	return (int##N##_t)res;\
}

ADDU(8)
SUBU(8)
DIVU(8)
MULU(8, 16)
ADDS(8)
SUBS(8)
DIVS(8)
MULS(8, 16)

ADDU(16)
SUBU(16)
DIVU(16)
MULU(16, 32)
ADDS(16)
SUBS(16)
DIVS(16)
MULS(16, 32)

ADDU(32)
SUBU(32)
DIVU(32)
MULU(32, 64)
ADDS(32)
SUBS(32)
DIVS(32)
MULS(32, 64)

ADDU(64)
SUBU(64)
DIVU(64)
/* MULU(64, 128) */
ADDS(64)
SUBS(64)
DIVS(64)
/* MULS(64, 128) */

/* Specialized 64-bit multiplication with __{u}int128_t. */

#ifdef __SIZEOF_INT128__

uint64_t mulu64(uint64_t const x, uint64_t const y) {
	__uint128_t const res = (__uint128_t) x * (__uint128_t) y;
	uint64_t const hi = (uint64_t) (res >> 64);
	return (uint64_t) (res | (__uint128_t) (-!!hi));
}

int64_t muls64(int64_t const x, int64_t const y) {
	__int128_t res = (__int128_t) x * (__int128_t) y;
	uint64_t const res2 = (((uint64_t) x ^ (uint64_t) y) >> 63) + INT64_MAX;

	int64_t const hi = (int64_t) (res >> 64);
	int64_t const lo = (int64_t) res;

	if (hi != (lo >> 63)) {
		res = (__int128_t) res2;
	}

	return (int64_t) res;
}

#endif
