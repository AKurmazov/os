# This task was done with the aid of this hint
# https://unix.stackexchange.com/questions/309010/how-to-do-locking-a-file-from-a-shell-script
NUMBERS_FILE="ex2.txt"

if ln $NUMBERS_FILE file.lock; then
    for i in {1..1000}
    do
      last_number=$(tail -n 1 ex2.txt)
      ((last_number++))
      echo $last_number >> $NUMBERS_FILE
    done
    rm file.lock
else
    echo no lock files
fi
