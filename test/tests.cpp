// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(CheckPrimeTest, HandlesZeroAndOne) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrimeTest, HandlesSmallPrimes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
}

TEST(CheckPrimeTest, HandlesSmallNonPrimes) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(10));
    EXPECT_FALSE(checkPrime(12));
}

TEST(CheckPrimeTest, HandlesLargePrimes) {
    EXPECT_TRUE(checkPrime(97));
    EXPECT_TRUE(checkPrime(101));
    EXPECT_TRUE(checkPrime(103));
    EXPECT_TRUE(checkPrime(107));
    EXPECT_TRUE(checkPrime(109));
    EXPECT_TRUE(checkPrime(113));
}

TEST(CheckPrimeTest, HandlesLargeNonPrimes) {
    EXPECT_FALSE(checkPrime(100));
    EXPECT_FALSE(checkPrime(102));
    EXPECT_FALSE(checkPrime(104));
    EXPECT_FALSE(checkPrime(105));
    EXPECT_FALSE(checkPrime(106));
    EXPECT_FALSE(checkPrime(108));
    EXPECT_FALSE(checkPrime(110));
    EXPECT_FALSE(checkPrime(111));
    EXPECT_FALSE(checkPrime(112));
}

TEST(NPrimeTest, HandlesFirstPrimes) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
    EXPECT_EQ(nPrime(6), 13);
    EXPECT_EQ(nPrime(7), 17);
    EXPECT_EQ(nPrime(8), 19);
    EXPECT_EQ(nPrime(9), 23);
    EXPECT_EQ(nPrime(10), 29);
}

TEST(NPrimeTest, HandlesLaterPrimes) {
    EXPECT_EQ(nPrime(15), 47);
    EXPECT_EQ(nPrime(20), 71);
    EXPECT_EQ(nPrime(25), 97);
    EXPECT_EQ(nPrime(30), 113);
    EXPECT_EQ(nPrime(40), 173);
    EXPECT_EQ(nPrime(50), 229);
}

TEST(NPrimeTest, HandlesZero) {
    EXPECT_EQ(nPrime(0), 0);
}

TEST(NextPrimeTest, HandlesSmallNumbers) {
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(6), 7);
    EXPECT_EQ(nextPrime(7), 11);
    EXPECT_EQ(nextPrime(8), 11);
    EXPECT_EQ(nextPrime(9), 11);
    EXPECT_EQ(nextPrime(10), 11);
}

TEST(NextPrimeTest, HandlesLargerNumbers) {
    EXPECT_EQ(nextPrime(11), 13);
    EXPECT_EQ(nextPrime(12), 13);
    EXPECT_EQ(nextPrime(13), 17);
    EXPECT_EQ(nextPrime(14), 17);
    EXPECT_EQ(nextPrime(15), 17);
    EXPECT_EQ(nextPrime(16), 17);
    EXPECT_EQ(nextPrime(17), 19);
    EXPECT_EQ(nextPrime(18), 19);
    EXPECT_EQ(nextPrime(19), 23);
    EXPECT_EQ(nextPrime(20), 23);
    EXPECT_EQ(nextPrime(21), 23);
    EXPECT_EQ(nextPrime(22), 23);
    EXPECT_EQ(nextPrime(23), 29);
}

TEST(NextPrimeTest, HandlesNearPrimes) {
    EXPECT_EQ(nextPrime(100), 101);
    EXPECT_EQ(nextPrime(101), 103);
    EXPECT_EQ(nextPrime(102), 103);
    EXPECT_EQ(nextPrime(103), 107);
    EXPECT_EQ(nextPrime(104), 107);
    EXPECT_EQ(nextPrime(105), 107);
    EXPECT_EQ(nextPrime(106), 107);
    EXPECT_EQ(nextPrime(107), 109);
    EXPECT_EQ(nextPrime(108), 109);
    EXPECT_EQ(nextPrime(109), 113);
    EXPECT_EQ(nextPrime(110), 113);
}

TEST(SumPrimeTest, HandlesSmallRanges) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(4), 5);
    EXPECT_EQ(sumPrime(5), 5);
    EXPECT_EQ(sumPrime(6), 10);
    EXPECT_EQ(sumPrime(7), 10);
    EXPECT_EQ(sumPrime(8), 17);
    EXPECT_EQ(sumPrime(9), 17);
    EXPECT_EQ(sumPrime(10), 17);
    EXPECT_EQ(sumPrime(11), 17);
    EXPECT_EQ(sumPrime(12), 28);
    EXPECT_EQ(sumPrime(13), 28);
    EXPECT_EQ(sumPrime(14), 41);
}

TEST(SumPrimeTest, HandlesLargerRanges) {
    EXPECT_EQ(sumPrime(15), 41);
    EXPECT_EQ(sumPrime(16), 41);
    EXPECT_EQ(sumPrime(17), 41);
    EXPECT_EQ(sumPrime(18), 58);
    EXPECT_EQ(sumPrime(19), 58);
    EXPECT_EQ(sumPrime(20), 77);
    EXPECT_EQ(sumPrime(21), 77);
    EXPECT_EQ(sumPrime(22), 77);
    EXPECT_EQ(sumPrime(23), 77);
    EXPECT_EQ(sumPrime(24), 100);
    EXPECT_EQ(sumPrime(25), 100);
    EXPECT_EQ(sumPrime(26), 100);
    EXPECT_EQ(sumPrime(27), 100);
    EXPECT_EQ(sumPrime(28), 100);
    EXPECT_EQ(sumPrime(29), 100);
    EXPECT_EQ(sumPrime(30), 129);
    EXPECT_EQ(sumPrime(31), 129);
    EXPECT_EQ(sumPrime(32), 160);
    EXPECT_EQ(sumPrime(33), 160);
    EXPECT_EQ(sumPrime(34), 160);
    EXPECT_EQ(sumPrime(35), 160);
    EXPECT_EQ(sumPrime(36), 160);
    EXPECT_EQ(sumPrime(37), 160);
    EXPECT_EQ(sumPrime(38), 197);
    EXPECT_EQ(sumPrime(39), 197);
    EXPECT_EQ(sumPrime(40), 197);
}

TEST(SumPrimeTest, HandlesLargeRange) {
    uint64_t result = sumPrime(2000000);
    uint64_t expected = 142913828922;
    EXPECT_EQ(result, expected);
}

TEST(SumPrimeTest, HandlesBoundaryValues) {
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(4), 5);
    EXPECT_EQ(sumPrime(100), 1060);
}

TEST(SumPrimeTest, HandlesPerfectSquares) {
    EXPECT_EQ(sumPrime(25), 100);
    EXPECT_EQ(sumPrime(49), 328);
    EXPECT_EQ(sumPrime(121), 1060);
    EXPECT_EQ(sumPrime(169), 2186);
    EXPECT_EQ(sumPrime(289), 6592);
}