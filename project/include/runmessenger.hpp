#ifndef RUN_MESSENGER_HPP
#define RUN_MESSENGER_HPP
#include "G4UImessenger.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithAString.hh"

namespace msrfeed {
  // Forward declaration, to resolve circular dependency with RunAction
  // You still need to #include "runaction.hpp" in runmessenger.cpp
  class RunAction;

  // User-facing part of the UI: just for the user
  class RunMessenger: public G4UImessenger {
  public:
    RunMessenger(RunAction* runaction);
    ~RunMessenger();

    void SetNewValue(G4UIcommand* cmd, G4String val) override final;

  private:
    RunAction* m_runAction;
    G4UIdirectory* m_directory;
    G4UIcmdWithABool* m_saveDataCmd;
    G4UIcmdWithAString* m_savePathCmd;
  };  
}

#endif
