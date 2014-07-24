import eventlet
from eventlet import wsgi
from pprint import pformat
import json

def get_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/plain')])
    return ["Put resources!\n"]

def post_Resource(environ, start_response):

    length = int(environ.get('CONTENT_LENGTH','0'))
    contentinput = environ['wsgi.input'].read(length)

    jsoncontent = json.loads(contentinput)
    jsoncontent['file']['content'] = 'Goodbye'
 
    
    start_response("200 OK",[('Content-type', 'text/json')])
    return [json.dumps(jsoncontent)]

def put_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/plain')])
    return ["Put resources!\n"]

def delete_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/plain')])
    return ["Delete resources!\n"]


def RestfulMethod(method):
    return { 'POST': post_Resource,
             'PUT':  put_Resource,
             'GET':  get_Resource,
             'DELETE': delete_Resource
           } [method]
 

URL_PATTERNS= (
    ('hi/','say_Resource'),
    ('hello/','say_hello'),
    )

class Dispatcher(object):

    def _match(self,path):
        path = path.split('/')[1]
        for url,app in URL_PATTERNS:
            if path in url:
                return app

    def __call__(self,environ, start_response):
      
        path = environ.get('PATH_INFO','/')
        method = environ.get('REQUEST_METHOD')
        contenttype = environ.get('CONTENT_TYPE')
        #Restful web requests:
        app = RestfulMethod(method)
        if app:
            return app(environ, start_response)
        else:
            start_response("404 NOT FOUND",[('Content-type', 'text/plain')])
            return ["Page dose not exists!"]

def say_Resource(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/html')])
    return ["kenshin say hi to you!\n"]

def say_hello(environ, start_response):
    start_response("200 OK",[('Content-type', 'text/html')])
    return ["kenshin say hello to you!\n"]

app = Dispatcher()

# option 1
#from  wsgiref import make_server
#httpd = make_server('', 8910, app)
#print "Serving on port 8910..."
#httpd.serve_forever()


#option 2
wsgi.server(eventlet.listen(('127.0.0.1',8910)), app)


