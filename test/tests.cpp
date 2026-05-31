// Copyright 2025 UNN-IASR
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(PrimeTest, BoundaryValues) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
}

TEST(PrimeTest, EvenNumbers) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(10));
    EXPECT_FALSE(checkPrime(100));
}

TEST(PrimeTest, KnownPrimes) {
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
    EXPECT_TRUE(checkPrime(23));
    EXPECT_TRUE(checkPrime(29));
    EXPECT_TRUE(checkPrime(31));
}

TEST(PrimeTest, CompositeNumbers) {
    EXPECT_FALSE(checkPrime(21));
    EXPECT_FALSE(checkPrime(27));
    EXPECT_FALSE(checkPrime(33));
    EXPECT_FALSE(checkPrime(35));
    EXPECT_FALSE(checkPrime(49));
}

TEST(NthPrimeTest, SmallIndices) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
    EXPECT_EQ(nPrime(6), 13);
}

TEST(NthPrimeTest, ZeroIndexCase) {
    EXPECT_EQ(nPrime(0), 0);
}

TEST(NthPrimeTest, LargerIndex) {
    EXPECT_EQ(nPrime(10), 29);
    EXPECT_EQ(nPrime(15), 47);
    EXPECT_EQ(nPrime(20), 71);
}

TEST(NextPrimeTest, BasicScenarios) {
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(5), 7);
}

TEST(NextPrimeTest, AfterCompositeNumbers) {
    EXPECT_EQ(nextPrime(8), 11);
    EXPECT_EQ(nextPrime(14), 17);
    EXPECT_EQ(nextPrime(20), 23);
    EXPECT_EQ(nextPrime(24), 29);
    EXPECT_EQ(nextPrime(30), 31);
}

TEST(NextPrimeTest, AfterLargePrime) {
    EXPECT_EQ(nextPrime(97), 101);
    EXPECT_EQ(nextPrime(101), 103);
}

TEST(SumPrimeTest, SmallBoundaries) {
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(5), 5);
    EXPECT_EQ(sumPrime(6), 10);
}

TEST(SumPrimeTest, MediumBoundaries) {
    EXPECT_EQ(sumPrime(10), 17);
    EXPECT_EQ(sumPrime(15), 41);
    EXPECT_EQ(sumPrime(20), 77);
}

TEST(SumPrimeTest, LargeBoundary) {
    uint64_t result = sumPrime(2000000);
    uint64_t expected = 142913828922ULL;
    EXPECT_EQ(result, expected);
}

