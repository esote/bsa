/* Branchfree saturating arithmetic -- values saturate instead of overflowing or
underflowing. */

#ifndef BSA_H
#define BSA_H

#include <stdint.h>

/* Unsigned 8-bit. */

uint8_t addu8(uint8_t const, uint8_t const);
uint8_t subu8(uint8_t const, uint8_t const);
uint8_t divu8(uint8_t const, uint8_t const);
uint8_t mulu8(uint8_t const, uint8_t const);

/* Signed 8-bit. */

int8_t adds8(int8_t const, int8_t const);
int8_t subs8(int8_t const, int8_t const);
int8_t divs8(int8_t const, int8_t const);
int8_t muls8(int8_t const, int8_t const);

/* Unsigned 16-bit. */

uint16_t addu16(uint16_t const, uint16_t const);
uint16_t subu16(uint16_t const, uint16_t const);
uint16_t divu16(uint16_t const, uint16_t const);
uint16_t mulu16(uint16_t const, uint16_t const);

/* Signed 16-bit. */

int16_t adds16(int16_t const, int16_t const);
int16_t subs16(int16_t const, int16_t const);
int16_t divs16(int16_t const, int16_t const);
int16_t muls16(int16_t const, int16_t const);

/* Unsigned 32-bit. */

uint32_t addu32(uint32_t const, uint32_t const);
uint32_t subu32(uint32_t const, uint32_t const);
uint32_t divu32(uint32_t const, uint32_t const);
uint32_t mulu32(uint32_t const, uint32_t const);

/* Signed 32-bit. */

int32_t adds32(int32_t const, int32_t const);
int32_t subs32(int32_t const, int32_t const);
int32_t divs32(int32_t const, int32_t const);
int32_t muls32(int32_t const, int32_t const);

/* Unsigned 64-bit. */

uint64_t addu64(uint64_t const, uint64_t const);
uint64_t subu64(uint64_t const, uint64_t const);
uint64_t divu64(uint64_t const, uint64_t const);
uint64_t mulu64(uint64_t const, uint64_t const);

/* Signed 64-bit. */

int64_t adds64(int64_t const, int64_t const);
int64_t subs64(int64_t const, int64_t const);
int64_t divs64(int64_t const, int64_t const);
int64_t muls64(int64_t const, int64_t const);

#endif /* BSA_H */
