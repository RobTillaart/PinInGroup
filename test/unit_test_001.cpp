//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-05
// PURPOSE: unit tests for the PinInGroup
//          https://github.com/RobTillaart/PinInGroup
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
// #define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
// #define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "PinInGroup.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_all)
{
  fprintf(stderr, "VERSION: %s\n", PININGROUP_LIB_VERSION);

  PinInGroup PIG;
  uint8_t ar[8] = {2, 3, 4, 5, 6, 7, 4, 4};

  assertEqual(0, PIG.size());
  assertEqual(16, PIG.free());
  assertFalse(PIG.isInGroup(2));

  PIG.add(8, ar, INPUT_PULLUP);
  assertEqual(8, PIG.size());
  assertEqual(8, PIG.free());
  
  for (int pin = 0; pin < 8; pin++)
  {
    fprintf(stderr, "%d\t%d\n", pin, PIG.isInGroup(pin));
  }
}

unittest_main()

// --------
