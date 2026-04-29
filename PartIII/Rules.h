#pragma once


struct Rule {
    double minSize;   // minimum legal size in cm (0 = no size limit)
    int    bagLimit;  // max number allowed per day
};