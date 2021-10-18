import os
import shutil

# known file extensions:
accepted_extensions = [
    '.pdf',
    '.doc', '.docx',
    '.tar', '.zip', '.7z', '.rar',
    '.README',
]

with open('student_id.txt', 'w') as f_id:

    for file in os.listdir('.'):
        if file[0] == '.':  # file is a hidden file. Ignore.
            continue

        filename, file_extension = os.path.splitext(file)

        if ( file_extension in accepted_extensions ):  # known file extension, move the file and delete the folder
                f_id.write(filename + '\n')

        else:
            print( 'Unacceptable file extension with {}'.format(file) )
