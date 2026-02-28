// Copyright 2025 UNN-IASR
#include <cstdint>
#include <vector>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  if (value == 2 || value == 3) {
    return true;
  }
  for (uint64_t i = 2; i * i <= value; i++) {
    if ((value % i) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  uint64_t position = 0;
  uint64_t desired = 1;
  while (position < n) {
    desired++;
    if (checkPrime(desired))
      position++;
  }
  return desired;
}

uint64_t nextPrime(uint64_t value) {
  if (value == UINT64_MAX) {
    return 0;
  }
  uint64_t next = value + 1;
  while (!checkPrime(next)) next++;
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) {
    return 0;
  }
  std::vector<bool> is_prime(hbound, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (uint64_t i = 2; i * i < hbound; i++) {
    if (is_prime[i]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        is_prime[j] = false;
      }
    }
  }
  uint64_t sum = 0;
  for (uint64_t i = 0; i < hbound; i++) {
    if (is_prime[i]) {
      sum += i;
    }
  }
  return sum;
}