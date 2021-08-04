#include <vector>
using namespace std;
struct IParticipant
{
    virtual void notify(IParticipant *origin, int value) = 0;
};

struct Mediator
{
    vector<IParticipant *> participants;

    void say(IParticipant *origin, int value)
    {
        for (auto participant : participants)
        {
            participant->notify(origin, value);
        }
    }
};

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.participants.push_back(this);
    }

    void notify(IParticipant *origin, int value) override
    {
        if (origin != this)
        {
            this->value += value;
        }
    }

    void say(int value)
    {
        mediator.say(this, value);
    }
};

