const http = require('http');
const url = require('url');

// write a nodejs server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

const server = http.createServer((req, res) => {
    const parsedUrl = url.parse(req.url, true);
    const pathname = parsedUrl.pathname;
    const query = parsedUrl.query;

    if (pathname === '/get') {
        if (query.key) {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('hello ' + query.key);
        } else {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('hello world');
        }
    }else if (pathname === '/DaysBetweenDates') {
        const date1 = new Date(query.date1);
        const date2 = new Date(query.date2);

        if (!isNaN(date1) && !isNaN(date2)) {
            const timeDiff = Math.abs(date2.getTime() - date1.getTime());
            const diffDays = Math.ceil(timeDiff / (1000 * 3600 * 24));
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Days between dates: ' + diffDays);
        } else {
            res.writeHead(400, { 'Content-Type': 'text/plain' });
            res.end('Invalid dates');
        }
        
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('method not supported');
    }
});

server.listen(4000, () => {
    console.log('server is listening on port 3000');
});

