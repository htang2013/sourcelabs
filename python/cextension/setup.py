from distutils.core import setup, Extension
setup(name='helloworld', version='2.0',  \
      ext_modules=[Extension('helloworld', ['hello.c'])])

