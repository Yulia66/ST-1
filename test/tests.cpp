// Copyright 2025 UNN-IASR
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}

TEST(CheckPrimeTest, SmallNonPrimes) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrimeTest, SmallPrimes) {
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
}

TEST(CheckPrimeTest, CompositeNumbers) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(15));
  EXPECT_FALSE(checkPrime(25));
}

TEST(NPrimeTest, FirstPrimes) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
  EXPECT_EQ(nPrime(4), 7);
  EXPECT_EQ(nPrime(5), 11);
}

TEST(NPrimeTest, ZeroIndex) {
  EXPECT_EQ(nPrime(0), 0);
}

TEST(NextPrimeTest, NextAfterSmallNumbers) {
  EXPECT_EQ(nextPrime(1), 2);
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(4), 5);
  EXPECT_EQ(nextPrime(10), 11);
}

TEST(NextPrimeTest, NextAfterPrimes) {
  EXPECT_EQ(nextPrime(3), 5);
  EXPECT_EQ(nextPrime(7), 11);
  EXPECT_EQ(nextPrime(13), 17);
}

TEST(SumPrimeTest, SumBelowSmallBounds) {
  EXPECT_EQ(sumPrime(2), 0);
  EXPECT_EQ(sumPrime(3), 2);
  EXPECT_EQ(sumPrime(6), 10);
}

TEST(SumPrimeTest, SumBelowLargerBounds) {
  EXPECT_EQ(sumPrime(11), 17);
  EXPECT_EQ(sumPrime(12), 28);
  EXPECT_EQ(sumPrime(20), 77);
}