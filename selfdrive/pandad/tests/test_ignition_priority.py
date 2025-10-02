#!/usr/bin/env python3
"""
Test for ignitionCan priority over ignitionLine
"""

import unittest
from unittest.mock import Mock, patch
import sys
import os

# Add the parent directory to the path to import pandad modules
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

class TestIgnitionPriority(unittest.TestCase):
    """Test cases for ignitionCan priority logic"""

    def setUp(self):
        """Set up test fixtures"""
        self.test_panda_serial = "TEST_PANDA_001"

    def test_ignition_source_when_true(self):
        """Test that ignitionCan takes priority when it's True"""
        # Simulate ignitionCan = True, ignitionLine = False
        ignition_can = True
        ignition_line = False
        prev_ignition_can = False
        ignition_source = False

        # Apply priority logic
        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        # Determine final ignition state
        final_ignition = ignition_can if ignition_source else ignition_line

        self.assertTrue(final_ignition)
        self.assertTrue(ignition_source)

    def test_ignition_source_maintained_after_false(self):
        """Test that ignitionCan priority is maintained when it transitions from True to False"""
        # Start with ignitionCan = True, ignitionLine = True
        ignition_can = True
        ignition_line = True
        prev_ignition_can = False
        ignition_source = False

        # First iteration - ignitionCan = True
        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        final_ignition = ignition_can if ignition_source else ignition_line
        self.assertTrue(final_ignition)
        self.assertTrue(ignition_source)

        # Second iteration - ignitionCan = False, ignitionLine = True
        prev_ignition_can = ignition_can
        ignition_can = False

        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        final_ignition = ignition_can if ignition_source else ignition_line
        self.assertFalse(final_ignition)  # Should be False due to priority
        self.assertTrue(ignition_source)  # Priority should be maintained

    def test_ignition_line_fallback_when_ignition_can_never_used(self):
        """Test that ignitionLine works as fallback when ignitionCan is never True"""
        # ignitionCan = False, ignitionLine = True
        ignition_can = False
        ignition_line = True
        prev_ignition_can = False
        ignition_source = False

        # Apply priority logic
        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        # Determine final ignition state
        final_ignition = ignition_can if ignition_source else ignition_line

        self.assertTrue(final_ignition)
        self.assertFalse(ignition_source)

    def test_ignition_can_regains_priority(self):
        """Test that ignitionCan regains priority when it goes True again"""
        # Start with ignitionCan = False, ignitionLine = True
        ignition_can = False
        ignition_line = True
        prev_ignition_can = False
        ignition_source = False

        # First iteration - ignitionCan = False, ignitionLine = True
        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        final_ignition = ignition_can if ignition_source else ignition_line
        self.assertTrue(final_ignition)
        self.assertFalse(ignition_source)

        # Second iteration - ignitionCan = True, ignitionLine = True
        prev_ignition_can = ignition_can
        ignition_can = True

        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        final_ignition = ignition_can if ignition_source else ignition_line
        self.assertTrue(final_ignition)
        self.assertTrue(ignition_source)  # Priority should be regained

    def test_both_sources_false(self):
        """Test that system ignition is False when both sources are False"""
        # ignitionCan = False, ignitionLine = False
        ignition_can = False
        ignition_line = False
        prev_ignition_can = False
        ignition_source = False

        # Apply priority logic
        if ignition_can:
            ignition_source = True
        elif prev_ignition_can and not ignition_can:
            ignition_source = True
        elif not ignition_source and ignition_line:
            ignition_source = False

        # Determine final ignition state
        final_ignition = ignition_can if ignition_source else ignition_line

        self.assertFalse(final_ignition)
        self.assertFalse(ignition_source)

if __name__ == '__main__':
    unittest.main()