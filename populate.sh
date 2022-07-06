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

            mkdir -p "${assignment}"

            cat <<- EOF >> "${assignment}/${README_FILENAME}"
				# $(echo "${assignment}" | tr '_' ' '): ${theme}
				[Contest link](<${link}>) (may be invalid)

				---

				# Tasks
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

            mkdir -p "${assignment}/${task}"

            cat <<- EOF >> "${assignment}/${README_FILENAME}"

				## ${count}. ${task} (${difficulty})

				[HackerRank link](<${link}>) (may be invalid)

				[Task statement](<./${task}/${README_FILENAME}>)
			EOF

            cat <<- EOF >> "${assignment}/${task}/${README_FILENAME}"
				# Task ${count}. ${task} (${difficulty})

				[HackerRank link](<${link}>) (may be invalid)

				<!-- TODO -->
			EOF
            ;;
    esac
done 3<"${INPUT}"
