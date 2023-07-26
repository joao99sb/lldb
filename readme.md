Font: https://www.youtube.com/watch?v=2GV0K9Y2MKA&t=494s

Setting breakpoints:
  (lldb) break set -f demo.cpp -l #
  (lldb) br s -f demo.cpp -l #
  (lldb) b demo.cpp : #

Breakpoints with Symbols:

  On function:
  (lldb) b square(int)
  
  On a class method:
  (lldb) b Demo::demo

  Insade a namespace
  (lldb) b LLDBDemo::add(int,int)



Manipulating Breakpoints:

  Linsting breakpoints:
  (lldb) br list

  Deleting breakpoints:
  (lldb) br del #
  (lldb) br del 


Stepping Around:

  Step Over:
  (lldb) next
  (lldb) n

  Step Into:
  (lldb) step
  (lldb) s

  Continue:
  (lldb) c

Inspecting Variables:

  Print Vatiables Contents:
  (lldb) p varName

  Frame Variables:
  (lldb) frame variable
  (lldb) fr v 

  Current Line:
  (lldb) frame select
  (lldb) fr s
    
  Variable Format:
  /x -> hex
  /t -> bin


Backtrace and Frames:
  Backtrace:
  (lldb) bt

  Switching Frames:
  (lldb) frame select #
  (lldb) f #

Clear default output:
  (lldb) shell clear

Using Watchpoints:
  Program must be ruinng in order to set the watch point.

  Global Variable:
  (lldb) watchpoint set variable globalVariavle
  (lldb) watchpoint set variable -w read |write | read_write globalVariable

  Member Variable:
  (lldb) b main
  (lldb) w s v d.memberVar
