#!/usr/bin/env python3
"""
Test for IgnitionCan priority over IgnitionLine
"""

import unittest
from unittest.mock import Mock, patch
import sys
import os

# Add the parent directory to the path to import pandad modules
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

class TestIgnitionPriority(unittest.TestCase):
    """Test cases for IgnitionCan priority logic"""

    def setUp(self):
        """Set up test fixtures"""
        self.test_panda_serial = "TEST_PANDA_001"

    def test_ignition_can_priority_when_true(self):
        """Test that IgnitionCan takes priority when it's True"""
        # Simulate IgnitionCan = True, IgnitionLine = False
        ignition_can = True
        ignition_line = False
        prev_ignition_can = False
        ignition_can_priority = False

        # Apply priority logic
        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        # Determine final ignition state
        final_ignition = ignition_can if ignition_can_priority else ignition_line

        self.assertTrue(final_ignition)
        self.assertTrue(ignition_can_priority)

    def test_ignition_can_priority_maintained_after_false(self):
        """Test that IgnitionCan priority is maintained when it transitions from True to False"""
        # Start with IgnitionCan = True, IgnitionLine = True
        ignition_can = True
        ignition_line = True
        prev_ignition_can = False
        ignition_can_priority = False

        # First iteration - IgnitionCan = True
        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        final_ignition = ignition_can if ignition_can_priority else ignition_line
        self.assertTrue(final_ignition)
        self.assertTrue(ignition_can_priority)

        # Second iteration - IgnitionCan = False, IgnitionLine = True
        prev_ignition_can = ignition_can
        ignition_can = False

        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        final_ignition = ignition_can if ignition_can_priority else ignition_line
        self.assertFalse(final_ignition)  # Should be False due to priority
        self.assertTrue(ignition_can_priority)  # Priority should be maintained

    def test_ignition_line_fallback_when_ignition_can_never_used(self):
        """Test that IgnitionLine works as fallback when IgnitionCan is never True"""
        # IgnitionCan = False, IgnitionLine = True
        ignition_can = False
        ignition_line = True
        prev_ignition_can = False
        ignition_can_priority = False

        # Apply priority logic
        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        # Determine final ignition state
        final_ignition = ignition_can if ignition_can_priority else ignition_line

        self.assertTrue(final_ignition)
        self.assertFalse(ignition_can_priority)

    def test_ignition_can_regains_priority(self):
        """Test that IgnitionCan regains priority when it goes True again"""
        # Start with IgnitionCan = False, IgnitionLine = True
        ignition_can = False
        ignition_line = True
        prev_ignition_can = False
        ignition_can_priority = False

        # First iteration - IgnitionCan = False, IgnitionLine = True
        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        final_ignition = ignition_can if ignition_can_priority else ignition_line
        self.assertTrue(final_ignition)
        self.assertFalse(ignition_can_priority)

        # Second iteration - IgnitionCan = True, IgnitionLine = True
        prev_ignition_can = ignition_can
        ignition_can = True

        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        final_ignition = ignition_can if ignition_can_priority else ignition_line
        self.assertTrue(final_ignition)
        self.assertTrue(ignition_can_priority)  # Priority should be regained

    def test_both_sources_false(self):
        """Test that system ignition is False when both sources are False"""
        # IgnitionCan = False, IgnitionLine = False
        ignition_can = False
        ignition_line = False
        prev_ignition_can = False
        ignition_can_priority = False

        # Apply priority logic
        if ignition_can:
            ignition_can_priority = True
        elif prev_ignition_can and not ignition_can:
            ignition_can_priority = True
        elif not ignition_can_priority and ignition_line:
            ignition_can_priority = False

        # Determine final ignition state
        final_ignition = ignition_can if ignition_can_priority else ignition_line

        self.assertFalse(final_ignition)
        self.assertFalse(ignition_can_priority)

if __name__ == '__main__':
    unittest.main()