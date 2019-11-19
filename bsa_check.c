#include <check.h>
#include <stdlib.h>

#include "bsa.h"

/* Unsigned 8-bit. */

START_TEST (test_addu8) {
	ck_assert(addu8(10U, 5U) == 15U);
	ck_assert(addu8(5U, UINT8_MAX - 1U) == UINT8_MAX);
} END_TEST

START_TEST (test_subu8) {
	ck_assert(subu8(10U, 5U) == 5U);
	ck_assert(subu8(0U, 5U) == 0U);
} END_TEST

START_TEST (test_divu8) {
	ck_assert(divu8(1U, 4U) == 0U);
	ck_assert(divu8(UINT8_MAX, 3U) == 85U);
} END_TEST

START_TEST (test_mulu8) {
	ck_assert(mulu8(3U, 6U) == 18U);
	ck_assert(mulu8(127U, 9U) == UINT8_MAX);
} END_TEST

/* Unsigned 16-bit. */

START_TEST (test_addu16) {
	ck_assert(addu16(10U, 5U) == 15U);
	ck_assert(addu16(5U, UINT16_MAX - 1U) == UINT16_MAX);
} END_TEST

START_TEST (test_subu16) {
	ck_assert(subu16(10U, 5U) == 5U);
	ck_assert(subu16(0U, 5U) == 0U);
} END_TEST

START_TEST (test_divu16) {
	ck_assert(divu16(1U, 4U) == 0U);
	ck_assert(divu16(UINT16_MAX, 3U) == 21845U);
} END_TEST

START_TEST (test_mulu16) {
	ck_assert(mulu16(3U, 6U) == 18U);
	ck_assert(mulu16(40123U, 9U) == UINT16_MAX);
} END_TEST

/* Unsigned 32-bit. */

START_TEST (test_addu32) {
	ck_assert(addu32(10U, 5U) == 15U);
	ck_assert(addu32(5U, UINT32_MAX - 1U) == UINT32_MAX);
} END_TEST

START_TEST (test_subu32) {
	ck_assert(subu32(10U, 5U) == 5U);
	ck_assert(subu32(0U, 5U) == 0U);
} END_TEST

START_TEST (test_divu32) {
	ck_assert(divu32(1U, 4U) == 0U);
	ck_assert(divu32(UINT32_MAX, 3U) == 1431655765U);
} END_TEST

START_TEST (test_mulu32) {
	ck_assert(mulu32(3U, 6U) == 18U);
	ck_assert(mulu32(536870912U, 9U) == UINT32_MAX);
} END_TEST

/* Unsigned 64-bit. */

START_TEST (test_addu64) {
	ck_assert(addu64(10UL, 5UL) == 15UL);
	ck_assert(addu64(5UL, UINT64_MAX - 1UL) == UINT64_MAX);
} END_TEST

START_TEST (test_subu64) {
	ck_assert(subu64(10UL, 5UL) == 5UL);
	ck_assert(subu64(0UL, 5UL) == 0UL);
} END_TEST

START_TEST (test_divu64) {
	ck_assert(divu64(1UL, 4UL) == 0UL);
	ck_assert(divu64(UINT64_MAX, 3UL) == 6148914691236517205UL);
} END_TEST

START_TEST (test_mulu64) {
	ck_assert(mulu64(3UL, 6UL) == 18UL);
	ck_assert(mulu64(2305843009213693952UL, 9UL) == UINT64_MAX);
} END_TEST

/* Signed 8-bit. */

START_TEST (test_adds8) {
	ck_assert(adds8(-3, 15) == 12);
	ck_assert(adds8(-2, INT8_MIN) == INT8_MIN);
	ck_assert(adds8(5, INT8_MAX - 3) == INT8_MAX);
} END_TEST

START_TEST (test_subs8) {
	ck_assert(subs8(3, -15) == 18);
	ck_assert(subs8(INT8_MIN + 2, 3) == INT8_MIN);
	ck_assert(subs8(INT8_MAX - 3, -5) == INT8_MAX);
} END_TEST

START_TEST (test_divs8) {
	ck_assert(divs8(15, -3) == -5);
	ck_assert(divs8(INT8_MIN, -1) == INT8_MAX);
} END_TEST

START_TEST (test_muls8) {
	ck_assert(muls8(-15, 3) == -45);
	ck_assert(muls8(INT8_MIN, 2) == INT8_MIN);
	ck_assert(muls8(INT8_MAX, 2) == INT8_MAX);
	ck_assert(muls8(INT8_MAX, -2) == INT8_MIN);
} END_TEST

/* Signed 16-bit. */

START_TEST (test_adds16) {
	ck_assert(adds16(-3, 15) == 12);
	ck_assert(adds16(-2, INT16_MIN) == INT16_MIN);
	ck_assert(adds16(5, INT16_MAX - 3) == INT16_MAX);
} END_TEST

START_TEST (test_subs16) {
	ck_assert(subs16(3, -15) == 18);
	ck_assert(subs16(INT16_MIN + 2, 3) == INT16_MIN);
	ck_assert(subs16(INT16_MAX - 3, -5) == INT16_MAX);
} END_TEST

START_TEST (test_divs16) {
	ck_assert(divs16(15, -3) == -5);
	ck_assert(divs16(INT16_MIN, -1) == INT16_MAX);
} END_TEST

START_TEST (test_muls16) {
	ck_assert(muls16(-15, 3) == -45);
	ck_assert(muls16(INT16_MIN, 2) == INT16_MIN);
	ck_assert(muls16(INT16_MAX, 2) == INT16_MAX);
	ck_assert(muls16(INT16_MAX, -2) == INT16_MIN);
} END_TEST

/* Signed 32-bit. */

START_TEST (test_adds32) {
	ck_assert(adds32(-3, 15) == 12);
	ck_assert(adds32(-2, INT32_MIN) == INT32_MIN);
	ck_assert(adds32(5, INT32_MAX - 3) == INT32_MAX);
} END_TEST

START_TEST (test_subs32) {
	ck_assert(subs32(3, -15) == 18);
	ck_assert(subs32(INT32_MIN + 2, 3) == INT32_MIN);
	ck_assert(subs32(INT32_MAX - 3, -5) == INT32_MAX);
} END_TEST

START_TEST (test_divs32) {
	ck_assert(divs32(15, -3) == -5);
	ck_assert(divs32(INT32_MIN, -1) == INT32_MAX);
} END_TEST

START_TEST (test_muls32) {
	ck_assert(muls32(-15, 3) == -45);
	ck_assert(muls32(INT32_MIN, 2) == INT32_MIN);
	ck_assert(muls32(INT32_MAX, 2) == INT32_MAX);
	ck_assert(muls32(INT32_MAX, -2) == INT32_MIN);
} END_TEST

/* Signed 64-bit. */

START_TEST (test_adds64) {
	ck_assert(adds64(-3L, 15L) == 12L);
	ck_assert(adds64(-2L, INT64_MIN) == INT64_MIN);
	ck_assert(adds64(5L, INT64_MAX - 3L) == INT64_MAX);
} END_TEST

START_TEST (test_subs64) {
	ck_assert(subs64(3L, -15L) == 18L);
	ck_assert(subs64(INT64_MIN + 2L, 3L) == INT64_MIN);
	ck_assert(subs64(INT64_MAX - 3L, -5L) == INT64_MAX);
} END_TEST

START_TEST (test_divs64) {
	ck_assert(divs64(15L, -3L) == -5L);
	ck_assert(divs64(INT64_MIN, -1L) == INT64_MAX);
} END_TEST

START_TEST (test_muls64) {
	ck_assert(muls64(-15L, 3L) == -45L);
	ck_assert(muls64(INT64_MIN, 2L) == INT64_MIN);
	ck_assert(muls64(INT64_MAX, 2L) == INT64_MAX);
	ck_assert(muls64(INT64_MAX, -2L) == INT64_MIN);
} END_TEST

Suite *
suite_unsigned(void)
{
	Suite *const s = suite_create("Unsigned");
	TCase *const tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_addu8);
	tcase_add_test(tc_core, test_subu8);
	tcase_add_test(tc_core, test_divu8);
	tcase_add_test(tc_core, test_mulu8);

	tcase_add_test(tc_core, test_addu16);
	tcase_add_test(tc_core, test_subu16);
	tcase_add_test(tc_core, test_divu16);
	tcase_add_test(tc_core, test_mulu16);

	tcase_add_test(tc_core, test_addu32);
	tcase_add_test(tc_core, test_subu32);
	tcase_add_test(tc_core, test_divu32);
	tcase_add_test(tc_core, test_mulu32);

	tcase_add_test(tc_core, test_addu64);
	tcase_add_test(tc_core, test_subu64);
	tcase_add_test(tc_core, test_divu64);
	tcase_add_test(tc_core, test_mulu64);

	suite_add_tcase(s, tc_core);
	return s;
}

Suite *
suite_signed(void)
{
	Suite *const s = suite_create("Signed");
	TCase *const tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_adds8);
	tcase_add_test(tc_core, test_subs8);
	tcase_add_test(tc_core, test_divs8);
	tcase_add_test(tc_core, test_muls8);

	tcase_add_test(tc_core, test_adds16);
	tcase_add_test(tc_core, test_subs16);
	tcase_add_test(tc_core, test_divs16);
	tcase_add_test(tc_core, test_muls16);

	tcase_add_test(tc_core, test_adds32);
	tcase_add_test(tc_core, test_subs32);
	tcase_add_test(tc_core, test_divs32);
	tcase_add_test(tc_core, test_muls32);

	tcase_add_test(tc_core, test_adds64);
	tcase_add_test(tc_core, test_subs64);
	tcase_add_test(tc_core, test_divs64);
	tcase_add_test(tc_core, test_muls64);

	suite_add_tcase(s, tc_core);
	return s;
}

int
main(void)
{
	SRunner *const sr = srunner_create(suite_unsigned());
	srunner_add_suite(sr, suite_signed());

	/* Otherwise valgrind complains. */
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_NORMAL);

	int const number_failed = srunner_ntests_failed(sr);

	srunner_free(sr);

	return number_failed != 0;
}
