class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle= hour*30.0 ;
        double extra_hour_angle= (double(minutes)/60.0)*30;
        double total_hour_angle= hour_angle + extra_hour_angle;
        
        double min_angle= (double(minutes)/60.0)*360;
        
        double diff= abs(min_angle-total_hour_angle);
        if(diff>180)
            return 360- diff;
        return diff;
    }
};