/* BSA unit testing */

#include <check.h>
#include <limits.h>
#include <stdlib.h>

#include "bsa.h"

/* unsigned 32-bit */

START_TEST (test_addu32) {
	ck_assert(addu32(10U, 5U) == 15U);
	ck_assert(addu32(5U, UINT_MAX - 1U) == UINT_MAX);
} END_TEST

START_TEST (test_subu32) {
	ck_assert(subu32(10U, 5U) == 5U);
	ck_assert(subu32(0U, 5U) == 0U);
} END_TEST

START_TEST (test_divu32) {
	ck_assert(divu32(1U, 4U) == 0U);
	ck_assert(divu32(UINT_MAX, 3U) == 1431655765U);
} END_TEST

START_TEST (test_mulu32) {
	ck_assert(mulu32(3U, 6U) == 18U);
	ck_assert(mulu32(536870912U, 9U) == UINT_MAX);
} END_TEST

/* unsigned 64-bit */

START_TEST (test_addu64) {
	ck_assert(addu64(10UL, 5UL) == 15UL);
	ck_assert(addu64(5UL, ULONG_MAX - 1UL) == ULONG_MAX);
} END_TEST

START_TEST (test_subu64) {
	ck_assert(subu64(10UL, 5UL) == 5UL);
	ck_assert(subu64(0UL, 5UL) == 0UL);
} END_TEST

START_TEST (test_divu64) {
	ck_assert(divu64(1UL, 4UL) == 0UL);
	ck_assert(divu64(ULONG_MAX, 3UL) == 6148914691236517205UL);
} END_TEST

START_TEST (test_mulu64) {
	ck_assert(mulu64(3UL, 6UL) == 18UL);
	ck_assert(mulu64(2305843009213693952UL, 9UL) == ULONG_MAX);
} END_TEST

/* signed 32-bit */

START_TEST (test_adds32) {
	ck_assert(adds32(-3, 15) == 12);
	ck_assert(adds32(-2, INT_MIN) == INT_MIN);
	ck_assert(adds32(5, INT_MAX - 3) == INT_MAX);
} END_TEST

START_TEST (test_subs32) {
	ck_assert(subs32(3, -15) == 18);
	ck_assert(subs32(INT_MIN + 2, 3) == INT_MIN);
	ck_assert(subs32(INT_MAX - 3, -5) == INT_MAX);
} END_TEST

START_TEST (test_divs32) {
	ck_assert(divs32(15, -3) == -5);
	/* only case where it can overflow */
	ck_assert(divs32(INT_MIN, -1) == INT_MAX);
} END_TEST

START_TEST (test_muls32) {
	ck_assert(muls32(-15, 3) == -45);
	ck_assert(muls32(INT_MIN, 2) == INT_MIN);
	ck_assert(muls32(INT_MAX, 2) == INT_MAX);
	ck_assert(muls32(INT_MAX, -2) == INT_MIN);
} END_TEST

/* signed 64-bit */

START_TEST (test_adds64) {
	ck_assert(adds64(-3L, 15L) == 12L);
	ck_assert(adds64(-2L, LONG_MIN) == LONG_MIN);
	ck_assert(adds64(5L, LONG_MAX - 3L) == LONG_MAX);
} END_TEST

START_TEST (test_subs64) {
	ck_assert(subs64(3L, -15L) == 18L);
	ck_assert(subs64(LONG_MIN + 2L, 3L) == LONG_MIN);
	ck_assert(subs64(LONG_MAX - 3L, -5L) == LONG_MAX);
} END_TEST

START_TEST (test_divs64) {
	ck_assert(divs64(15L, -3L) == -5L);
	/* only case where it can overflow */
	ck_assert(divs64(LONG_MIN, -1L) == LONG_MAX);
} END_TEST

START_TEST (test_muls64) {
	ck_assert(muls64(-15L, 3L) == -45L);
	ck_assert(muls64(LONG_MIN, 2L) == LONG_MIN);
	ck_assert(muls64(LONG_MAX, 2L) == LONG_MAX);
	ck_assert(muls64(LONG_MAX, -2L) == LONG_MIN);
} END_TEST

Suite * bsa_suite(void) {
	Suite *const s = suite_create("BSA");
	TCase *const tc_core = tcase_create("Core");

	/* unsigned 32-bit */
	tcase_add_test(tc_core, test_addu32);
	tcase_add_test(tc_core, test_subu32);
	tcase_add_test(tc_core, test_divu32);
	tcase_add_test(tc_core, test_mulu32);

	/* unsigned 64-bit */
	tcase_add_test(tc_core, test_addu64);
	tcase_add_test(tc_core, test_subu64);
	tcase_add_test(tc_core, test_divu64);
	tcase_add_test(tc_core, test_mulu64);

	/* signed 32-bit */
	tcase_add_test(tc_core, test_adds32);
	tcase_add_test(tc_core, test_subs32);
	tcase_add_test(tc_core, test_divs32);
	tcase_add_test(tc_core, test_muls32);

	/* signed 64-bit */
	tcase_add_test(tc_core, test_adds64);
	tcase_add_test(tc_core, test_subs64);
	tcase_add_test(tc_core, test_divs64);
	tcase_add_test(tc_core, test_muls64);

	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	Suite *const s = bsa_suite();
	SRunner *const sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);

	int const number_failed = srunner_ntests_failed(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
