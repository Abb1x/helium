project('helium','c')

c_files = [

]

c_args = ['-Os','-Wall','-Wextra','-Werror','-ansi','-I./','-fPIC']

subdir('debug/')
subdir('data/')
shared_library('helium',c_files,c_args: c_args)
