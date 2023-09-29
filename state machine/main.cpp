#include <iostream>
#include <tuple>
#include <variant>
#include <functional>

int speed = 0;

template <typename... States>
class StateMachine
{
    public:
    template <typename State>
    void transitionTo()
    {
        currentState = &std::get<State>(states);
    }
    
    template <typename Event>
    void handle(const Event& event)
    {
        auto passEventToState = [this, &event] (auto statePtr) {
            statePtr->handle(event).execute(*this);
        };
        std::visit(passEventToState, currentState);
    }
    
    private:
    std::tuple<States...> states;
    std::variant<States*...> currentState{ &std::get<0>(states) };
};
  
template <typename State>
struct TransitionTo
{
    template <typename Machine>
    void execute(Machine& machine)
    {
        machine.template transitionTo<State>();
    }
};
  
struct Nothing
{
    template <typename Machine>
    void execute(Machine&)
    {
    }
};
  
struct OpenEvent
{
};
  
struct CloseEvent
{
};

struct DoubleEvent
{
};
  
struct ClosedState;
struct OpenState;
struct DoubleSpeedState;
  
struct ClosedState
{
    TransitionTo<OpenState> handle(const OpenEvent&) const
    {
        std::cout << "Start the motor..." << std::endl;
        speed = 1;
        return {};
    }
    
    Nothing handle(const CloseEvent&) const
    {
        std::cout << "Can not stop the motor beacuse it's not powered yet!!!" << std::endl;
        return {};
    }

    Nothing handle(const DoubleEvent&) const
    {
        std::cout << "Can not double the speed of the motor. Motor is not working" << std::endl;
        return {};
    }
};
  
struct OpenState
{
    Nothing handle(const OpenEvent&) const
    {
        std::cout << "Can not start the motor. It is already working.!" << std::endl;
        return {};
    }
    
    TransitionTo<ClosedState> handle(const CloseEvent&) const
    {
        std::cout << "Stopping the motor..." << std::endl;
        speed = 0;
        return {};
    }

    TransitionTo<DoubleSpeedState> handle(const DoubleEvent&) const
    {
        std::cout << "Doubling the speed of the motor" << std::endl;
        speed = speed *2;
        return {};
    }
};

struct DoubleSpeedState
{
    TransitionTo<ClosedState> handle(const CloseEvent&) const
    {
        std::cout << "Stopping the motor..." << std::endl;
        speed = 0;
        return {};
    }

    Nothing handle(const OpenEvent&) const
    {
        std::cout << "Can not start the motor. It is already working.!" << std::endl;
        return {};
    }

    TransitionTo<DoubleSpeedState> handle(const DoubleEvent&) const
    {
        std::cout << "Doubling the speed of the motor" << std::endl;
        speed = speed *2;
        return {};
    }
};
  
using Motor = StateMachine<ClosedState, OpenState, DoubleSpeedState>;

int main()
{
    Motor motor;
    
    motor.handle(OpenEvent{}); 
    printf("The speed of the motor is %d\n", speed);
    motor.handle(CloseEvent{});
    printf("The speed of the motor is %d\n", speed);
    
    motor.handle(CloseEvent{});
    printf("The speed of the motor is %d\n", speed);
    motor.handle(OpenEvent{});
    printf("The speed of the motor is %d\n", speed);

    motor.handle(OpenEvent{});
    printf("The speed of the motor is %d\n", speed);
    motor.handle(DoubleEvent{});
    printf("The speed of the motor is %d\n", speed);
    motor.handle(DoubleEvent{});
    printf("The speed of the motor is %d\n", speed);
    motor.handle(DoubleEvent{});
    printf("The speed of the motor is %d\n", speed);
    motor.handle(CloseEvent{});
    printf("The speed of the motor is %d\n", speed);
  
return 0;
}