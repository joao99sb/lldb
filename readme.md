setting breakpoints:
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
