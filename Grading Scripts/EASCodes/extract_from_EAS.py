import os
import shutil

# known file extensions:
accepted_extensions = [
    '.pdf',
    '.doc', '.docx',
    '.tar', '.zip', '.7z', '.rar',
    '.README',
]

visited_files_paths= []

with open('submission_time.txt', 'w') as f_time, open('student_id.txt', 'w') as f_id:

    for dir in os.listdir('.'):
        cur_path= './' + dir
        if not os.path.isdir(cur_path):
            continue

        student_id= dir

        # The Assignment Type ------------------------------------------------------
        the_assign_type= None
        for assign_type in os.listdir(cur_path):
            if not os.path.isdir(cur_path + '/' + assign_type): #TODO
                continue
            the_assign_type= assign_type

        if(the_assign_type == None):
            raise Exception('the_assign_type is None.')
        cur_path= cur_path + '/' + the_assign_type

        # The Last Submission Time -------------------------------------------------
        sorted_file_list= os.listdir(cur_path); sorted_file_list.sort()
        while sorted_file_list[0][0] == '.': #TODO
            sorted_file_list.pop(0)
        
        the_last_submission_time= None
        if len(sorted_file_list) > 0:
            the_last_submission_time= sorted_file_list.pop(-1)
        else:
            raise Exception('sorted_file_list is empty.')

        #remove all other submissions #TODO placement
        submission_time_interval= [ the_last_submission_time[5:17] ]
        if len(sorted_file_list) > 0:
            submission_time_interval.insert(0, sorted_file_list[0][5:17])

            for f in sorted_file_list:
                if os.path.isdir(cur_path + '/' + f):
                    shutil.rmtree(cur_path + '/' + f)

        cur_path= cur_path + '/' + the_last_submission_time

        f_id.write(student_id + '\n')
        f_time.write( str(submission_time_interval) + '\n')
        # Files --------------------------------------------------------------------
        for f in os.listdir(cur_path):
            if f[0] == '.':  # file is a hidden file. ignore
                continue
            filename, file_extension = os.path.splitext(f)
            visited_files_paths.append( cur_path + '/' + f )

            if ( file_extension in accepted_extensions ):  # known file extension, move the file and delete the folder
                shutil.move(
                    cur_path + "/" + f,
                    ''.join( [ student_id, file_extension ] )
                )

            else:
                print( 'Unacceptable file extension in {}, I won\'t touch this\
                        file; nevertheless, it will be recorded "in dont_delete_me.txt"'.format(cur_path) )

# remove empty dirs now
for f in [x[0] for x in os.walk('.', topdown= False)]: #x= (dirpath, dirnames, filenames)
    if os.path.isdir(f):
        dirContents= os.listdir(f)
        if len(dirContents) == 0 or all(d[0] == '.' for d in dirContents):
            shutil.rmtree(f)


with open('dont_delete_me.txt', 'w') as f_dont_delete_me:
    for f in visited_files_paths:
        f_dont_delete_me.write(f + '\n')
