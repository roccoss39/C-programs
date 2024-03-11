#ifndef ROBOT_H_
#define ROBOT_H_

class Robot
{
public:
    bool Turn_right(double Value);
    bool Turn_left(double Value);
    bool Hoist_right_arm(double Value);
    bool Hoist_left_arm(double Value);
    bool Go_forward(double Value);
    bool Go_back(double Value);
    void Commit();
};

#endif /* ROBOT_H_ */