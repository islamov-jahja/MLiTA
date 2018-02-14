program AISD_Praktika_1;
type
  Matr = array [1..10, 1..10] of char;
var
  Matrix: Matr;
  CounterOfCheckers, i , j, x, y, countChecker: integer;
  F1, F2: text;     
  
procedure Metka(Matrix: Matr; i, j: integer; var CounterOfCheckers, countChecker: integer);
begin
  if ((Matrix[i-1, j-1] <> '0') and (Matrix[i-1, j-1] <> '#') and (Matrix[i-2, j-2] <> '1') and (Matrix[i-2, j-2] <> '#'))
  then
    begin  
      writeln('-1', '-1');      
      Matrix[i-1, j-1] := '0';
      countChecker := countChecker + 1;
      writeln(i-1, j-1, '  zum', countChecker - 1);
      Metka(Matrix, i-2, j-2, CounterOfCheckers, countChecker); 
      Matrix[i-1, j-1] := '1'; 
    end;
  if ((Matrix[i-1, j+1] <> '0') and (Matrix[i-1, j+1] <> '#') and (Matrix[i-2, j+2] <> '1') and (Matrix[i-2, j+2] <> '#'))
  then
    begin 
      writeln('-1', '+1');
      Matrix[i-1, j+1] := '0';
      countChecker := countChecker + 1;
      writeln(i-1, j-1, '  zum', countChecker - 1);
      Metka(Matrix, i-2, j+2, CounterOfCheckers, countChecker);
      Matrix[i-1, j+1] := '1'; 
    end; 
  if ((Matrix[i+1, j-1] <> '0') and (Matrix[i+1, j-1] <> '#') and (Matrix[i+2, j-2] <> '1') and (Matrix[i+2, j-2] <> '#'))
  then
    begin
      writeln('+1', '-1');                     
      Matrix[i+1, j-1] := '0';
      countChecker := countChecker + 1;
      writeln(i-1, j-1, '  zum', countChecker - 1, Matrix[4][7]);
      Metka(Matrix, i+2, j-2, CounterOfCheckers, countChecker);
      Matrix[i+1, j-1] := '1';
    end;
  if ((Matrix[i+1, j+1] <> '0') and (Matrix[i+1, j+1] <> '#') and (Matrix[i+2, j+2] <> '1') and (Matrix[i+2, j+2] <> '#'))
  then
    begin
      writeln('+1', '+1');
      Matrix[i+1, j+1] := '0';
      countChecker := countChecker + 1;
      writeln(i-1, j-1, '  zum', countChecker -1);
      Metka(Matrix, i+2, j+2, CounterOfCheckers, countChecker);
      Matrix[i+1, j+1] := '1';
    end;
  if countChecker > CounterOfCheckers
  then
    CounterOfCheckers := countChecker;
    writeln(Matrix[4][7]); 
  writeln(i-1, j-1, ' ',  CounterOfCheckers, ' ', countChecker);
  countChecker := countChecker - 1;     
  readln;
end;
  
begin
  x := 0;
  y := 0;
  assign(F1, 'input.txt');
  assign(F2, 'output.txt');
  reset(F1);
  rewrite(F2);
  for i := 1 to 10 do
    for j := 1 to 10 do
      if ((i = 1) or (i = 10) or (j = 1) or (j = 10))
      then
        matrix[i, j] := '#';
  
  i := 2;
  j := 2;
  while not EOF(F1)
  do
    begin
      while not eoln(F1)
      do
        begin
          read(F1, Matrix[i, j]);
          if (Matrix[i, j] = '2')
          then
            begin
              x := i;
              y := j;
              Matrix[i, j] := '0'
            end;
          j := j + 1;
        end;
        readln(F1);
        i := i + 1;
        j := 2;
    end;
  writeln(Matrix[6][7]);
  CounterOfCheckers := 0;
  countChecker := 0;
  Metka(Matrix, x, y, CounterOfCheckers, countChecker);    
  writeln(F2, CounterOfCheckers);
end.
