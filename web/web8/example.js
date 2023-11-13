const axios = require('axios')

let items = {};

axios.get('https://www.fastmock.site/mock/cb41981f89575a6219c7312c0579f319/api/ACM/items')
    .then((response) => {
        items = JSON.parse(response.data);
    })
    .catch((err) => {
        console.log(err);
    })