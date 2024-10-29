#ifndef _SCHEDULEABLE_H_
#define _SCHEDULEABLE_H_

class Scheduleable {
  bool exited;
  bool ready;
  bool paused;
  Scheduleable* next_p;
  public:
  Scheduleable();
  bool is_exited();
  bool is_ready();
  bool is_paused();
  Scheduleable* get_next_p();
  virtual void call();
  virtual void call_bg();
  void pause();
  void resume();
  void reset();
  void _exit();
  void _ready();
};

#endif