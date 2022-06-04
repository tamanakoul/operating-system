echo -n "enter filename"
read filename
if [! - $filename]
then
echo "filename $ filename doesn't exist"
exit
fi
+z '[a-z]''[A-Z]' < $filename