#ifndef UNITCONVERTER_HPP
#define UNITCONVERTER_HPP

class UnitConverter {
public:
    double days_to_hours(double days);
    double years_to_days(double years);
    double minutes_to_days(double minutes);
    double days_to_minutes_and_seconds(double days, double& minutes, double& seconds);
    void years_to_months_weeks_days(double years, double& months, double& weeks, double& days);
};

#endif