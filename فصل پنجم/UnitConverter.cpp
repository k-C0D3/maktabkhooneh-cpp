#include "UnitConverter.hpp"

double UnitConverter::days_to_hours(double days) {
    return days * 24;
}

double UnitConverter::years_to_days(double years) {
    return years * 365;
}

double UnitConverter::minutes_to_days(double minutes) {
    return minutes / (24 * 60);
}

double UnitConverter::days_to_minutes_and_seconds(double days, double& minutes, double& seconds) {
    minutes = days  *24*  60;
    seconds = days  *24*  60 * 60;
    return days;
}

void UnitConverter::years_to_months_weeks_days(double years, double& months, double& weeks, double& days) {
    months = years * 12;
    weeks = years * 52;
    days = years * 365;
}