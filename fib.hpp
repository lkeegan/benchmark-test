#pragma once

int fib(int const i) {
  if (i <= 1) {
    return 1;
  }
  return fib(i - 2) + fib(i - 1);
}