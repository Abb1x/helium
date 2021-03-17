project('helium','c')

c_files = [

]

c_args = ['-Os','-Wall','-Wextra','-Werror','-ansi','-I../include','-fPIC']

subdir('src/debug/')
subdir('src/data/')
shared_library('helium',c_files,c_args: c_args)
