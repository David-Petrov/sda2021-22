#!/usr/bin/env sh

INPUT="$(realpath -m "${1}")"

README_FILENAME="README.md"

DELIM=";"

assignment=""
count="0"

while read -r line <&3; do
    case "${line}" in
        h-*|k-*|e-*)
            assignment="$( \
                echo "${line}" | \
                cut -d "${DELIM}" -f 1 | \
                sed 's/^h-/Homework_/;
                     s/^k-/Test_/;
                     s/^e-/Exam_/' \
                )"
            theme="$(echo "${line}" | cut -d "${DELIM}" -f 2)"
            link="$(echo "${line}" | cut -d "${DELIM}" -f 3)"
            count="0"

			
            cat <<- EOF >> "out.txt"
				### [$(echo "${assignment}" | tr '_' ' ')](<./${assignment}/${README_FILENAME}>): ${theme}

			EOF
            ;;
        *)
            task="$(echo "${line}" | cut -d "${DELIM}" -f 1)"
            difficulty="$( \
                echo "${line}" | \
                cut -d "${DELIM}" -f 2 | \
                sed 's/e/Easy/;
                     s/m/Medium/;
                     s/h/Hard/' \
                )"
            link="$(echo "${line}" | cut -d "${DELIM}" -f 3)"
            count="$(echo "${count} + 1" | bc)"

            cat <<- EOF >> "out.txt"
				${count}. [${task}](<./${assignment}/${task}/${README_FILENAME}>) (${difficulty})

			EOF
            ;;
    esac
done 3<"${INPUT}"
