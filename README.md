## Building the DLL

```
gcc -c test.cpp
gcc -shared -o test.dll test.o
```

## Running in `irb`
```ruby
load 'test.rb'

Library.process_pages 0, 'crap', %w(one two three)
```
