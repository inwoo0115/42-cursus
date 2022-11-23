cat /etc/passwd | grep -v '#' | awk "NR%2==0" | sed -e "s/^/ ,/" | cut -d ":" -f 1  | rev | sort -r | sed "$FT_LINE1,$FT_LINE2 !d" | tr -d "\n" | sed 's/, $/./g' 
