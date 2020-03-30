sudo blktrace /dev/sda -a issue -a complete -o - | blkparse -f "%M %m %d %a %S %9n %5T.%9t\n" -i -
