/* Branchfree saturating arithmetic -- values saturate instead of overflowing or
underflowing. */

#ifndef BSA_H
#define BSA_H

/* unsigned 32-bit */
unsigned addu32(unsigned const, unsigned const);
unsigned subu32(unsigned const, unsigned const);
unsigned divu32(unsigned const, unsigned const);
unsigned mulu32(unsigned const, unsigned const);

/* unsigned 64-bit */
unsigned long addu64(unsigned long const, unsigned long const);
unsigned long subu64(unsigned long const, unsigned long const);
unsigned long divu64(unsigned long const, unsigned long const);
unsigned long mulu64(unsigned long const, unsigned long const);

/* signed 32-bit */
signed adds32(signed const, signed const);
signed subs32(signed const, signed const);
signed divs32(signed, signed const);
signed muls32(signed const, signed const);

/* signed 64-bit */
signed long adds64(signed long const, signed long const);
signed long subs64(signed long const, signed long const);
signed long divs64(signed long, signed long const);
signed long muls64(signed long const, signed long const);

#endif /* BSA_H */
