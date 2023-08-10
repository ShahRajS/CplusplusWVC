#include <iostream>
#include "stats.h"
#include <cassert>

namespace main_savitch_2C {
	statistician::statistician() {
		reset();
	}

	void statistician::next(double r) {
		++count;
		total += r;
		if (count == 1) { //sets r as the default
			tinyest = r;
			largest = r;
		}
		else {
			if (r < tinyest) {
				tinyest = r;
			}

			if (r > largest) {
				largest = r;
			}
		}
	}

	void statistician::reset() {
		count = 0;
		total = 0.0;
	}

	int statistician::length() const{
		return count;
	}

	double statistician::sum() const {
		return total;
	}
	double statistician::mean() const {
		assert(count > 0);
		return (total / count);
	}
	double statistician::minimum() const {
		assert(count > 0);
		return tinyest;
	}
	double statistician::maximum() const {
		assert(count > 0);
		return largest;
	}

	statistician operator+ (const statistician& s1, const statistician& s2) {
		if (s1.count == 0) {
			return s2;
		}
		if (s2.count == 0) {
			return s1;
		}
		statistician stat_sum;
		 stat_sum.count = s1.length() + s2.length();
		 stat_sum.total = s1.sum() + s2.sum();
		 if (s1.tinyest < s2.tinyest) {
			 stat_sum.tinyest = s1.tinyest;
		 }
		 else {
			 stat_sum.tinyest = s2.tinyest;
		 }
		 if (s1.largest > s2.largest) {
			 stat_sum.largest = s1.largest;
		 }
		 else {
			 stat_sum.largest = s2.largest;
		 }
		 return stat_sum;
	}

	statistician operator* (double scale, const statistician& s) {
		statistician stat_scaled;
		stat_scaled.total = (s.sum() * scale);
		stat_scaled.count = s.length(); //number of values doesn't change
		if (scale > 0) {
			stat_scaled.tinyest = (s.tinyest * scale);
			stat_scaled.largest = (s.largest * scale);
		}
		else {
			stat_scaled.largest = (s.tinyest * scale);
			stat_scaled.tinyest = (s.largest * scale);
		}
		return stat_scaled;
	}

	bool operator ==(const statistician& s1, const statistician& s2) {
		if (s1.length() == s2.length() and s1.length() == 0) { //check for 0 length
			return true;
		}
		else if((s1.length() != s2.length()) or (s1.sum() != s2.sum()) or (s1.minimum() != s2.minimum()) or (s1.maximum() != s2.maximum())) {
			return false;
		}
		return true;
	}
}