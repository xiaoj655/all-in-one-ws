import './assets/main.css'
import store from './store/index'

import { createApp } from 'vue'
import App from './App.vue'


createApp(App).use(store).mount('#app')
