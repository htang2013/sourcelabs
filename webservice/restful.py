import eventlet
import urlparse
import pika
import wsgiref.util 
from eventlet import wsgi
from pprint import pformat
import re
import json


def host_app(environ, start_response):
    print "host_app"
    print environ.
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["host application called",]

def host_precheck(environ, start_response):

    print "host_precheck"
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["host precheck called",]

def host_install(environ, start_response):

    print "host_install"
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["host install called",]

def host_upgrade(environ, start_response):

    print "host_upgrade"
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["host upgrade called",]


def get_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["Get resources!\n"]

def post_Resource(environ, start_response):

    length = int(environ.get('CONTENT_LENGTH','0'))
    contentinput = environ['wsgi.input'].read(length)

    start_response("200 OK",[('Content-type', 'text/xml')])
    return ['Post resources!\n']

def put_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["Put resources!\n"]

def delete_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["Delete resources!\n"]


def option_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/xml')])
    return ["Option resources!\n"]

def RestfulMethod(method):
    return { 'POST': post_Resource,
             'PUT':  put_Resource,
             'GET':  get_Resource,
             'DELETE': delete_Resource,
             'OPTIONS': option_Resource,
           } [method]
 
class URLdispatcher(object):

    def __init__(self, patterns):
        self.patterns = patterns


    def __call__(self, environ, start_response):
        for key,value in environ.iteritems():
            print "%s = %s" % (key,value)
        path_info = environ.get('PATH_INFO','')
        script_name = environ.get('SCRIPT_NAME','')
        for regex, application in self.patterns:
             match = regex.match(path_info)
             if not match:
                continue
             extra_path_info = path_info[match.end():]
             if extra_path_info and not extra_path_info.startswith('/'):
                continue
             pos_args = match.groups()
             named_args = match.groupdict()
             cur_pos, cur_named = environ.get('wsgiorg.routing_args', ((), {}))
             new_pos = list(cur_pos) + list(pos_args)
             new_named = cur_named.copy()
             new_named.update(named_args)
             environ['wsgiorg.routing_args'] = (new_pos, new_named)
             environ['SCRIPT_NAME'] = script_name + path_info[:match.end()]
             environ['PATH_INFO'] = extra_path_info
             return application(environ, start_response)

        return self.page_not_found(environ, start_response)
         

    def page_not_found(self, environ, start_response):
        start_response("404 NOT FOUND",[('Content-type', 'text/plain')])
        return ["Page dose not exists!"]

dispatch_app = URLdispatcher([
       (re.compile(r'/hosts/$'), host_app),
       (re.compile(r'/hosts/([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})/precheck$'), host_precheck),
       (re.compile(r'/hosts/([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})/install$'), host_install),
       (re.compile(r'/host/([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})/upgrade$'), host_upgrade)])

 




# option 1
#from  wsgiref import make_server
#httpd = make_server('', 8910, app)
#print "Serving on port 8910..."
#httpd.serve_forever()


#option 2
wsgi.server(eventlet.listen(('127.0.0.1',8910)), dispatch_app)


