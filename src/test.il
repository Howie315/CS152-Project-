FUNCTION
IDENTIFIER: add
BEGINPARAM
IDENTIFIER: a
IDENTIFIER: b
ENDPARAM
BEGINSCOPE
IDENTIFIER: a
IDENTIFIER: b
ENDSCOPE
FUNCTION
IDENTIFIER: main
BEGINPARAM
ENDPARAM
BEGINSCOPE
IDENTIFIER: a
NUMBER: 20
IDENTIFIER: b
IDENTIFIER: c
IDENTIFIER: b
BEGINPARAM
ENDPARAM
IDENTIFIER: c
BEGINPARAM
ENDPARAM
IDENTIFIER: a
NUMBER: 0
IDENTIFIER: add
BEGINPARAM
IDENTIFIER: b
IDENTIFIER: c
ENDPARAM
BEGINPARAM
IDENTIFIER: a
NUMBER: 0
ENDPARAM
IDENTIFIER: a
NUMBER: 1
NUMBER: 100
BEGINPARAM
IDENTIFIER: a
NUMBER: 1
ENDPARAM
IDENTIFIER: a
NUMBER: 2
NUMBER: 200
BEGINPARAM
IDENTIFIER: a
NUMBER: 2
ENDPARAM
IDENTIFIER: a
NUMBER: 3
IDENTIFIER: a
NUMBER: 0
BEGINPARAM
IDENTIFIER: a
NUMBER: 1
IDENTIFIER: c
ENDPARAM
BEGINPARAM
IDENTIFIER: a
NUMBER: 3
ENDPARAM
IDENTIFIER: a
NUMBER: 4
BEGINPARAM
ENDPARAM
BEGINPARAM
IDENTIFIER: a
NUMBER: 4
ENDPARAM
ENDSCOPE
func add
. a
= a, $0
. b
= b, $1
. _temp0
+  _temp0, a, b
ret _temp0
endfunc
func main
.[] a, 20
. b
. c
. _temp1
.< _temp1
= b, _temp1
. _temp2
.< _temp2
= c, _temp2
. _temp3
param c
param b
call add, _temp3
[]= a, 0, _temp3
. _temp4
=[] _temp4, a, 0
.> _temp4
[]= a, 1, 100
. _temp5
=[] _temp5, a, 1
.> _temp5
[]= a, 2, 200
. _temp6
=[] _temp6, a, 2
.> _temp6
. _temp7
=[] _temp7, a, 0
. _temp8
=[] _temp8, a, 1
. _temp9
+  _temp9, _temp8, c
. _temp10
*  _temp10, _temp7, _temp9
[]= a, 3, _temp10
. _temp11
=[] _temp11, a, 3
.> _temp11
. _temp12
.< _temp12
[]= a, 4, _temp12
. _temp13
=[] _temp13, a, 4
.> _temp13
endfunc

symbol table:
--------------------
function: add
  locals: a
  locals: b
function: main
  locals: a
  locals: b
  locals: c
--------------------
