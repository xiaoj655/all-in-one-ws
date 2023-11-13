class Promise {
    constructor(executor) {
        // ...
        // 这里增加try catch
        try {
            executor(this.resolve, this.reject)
        } catch (e) {
            reject(e)
        }
    }
    then(onFulfilled, onRejected) {
        // 这里兼容下 onFulfilled 和 onRejected 的传参
        onFulfilled = typeof onFulfilled === 'function' ? onFulfilled : v => v
        onRejected = typeof onRejected === 'function' ? onRejected : err => {
            throw err
        }
        const promise2 = new Promise((resolve, reject) => {
            if (this.status === FULFILLED) {
                // 用 setTimeout 模拟异步
                setTimeout(() => {
                    try {
                        const x = onFulfilled(this.value)
                        resolvePromise(promise2, x, resolve, reject)
                    } catch (e) {
                        reject(e)
                    }
                }, 0)


            }
            if (this.status === REJECTED) {
                // 用 setTimeout 模拟异步
                setTimeout(() => {
                    try {
                        const x = onRejected(this.reason)
                        resolvePromise(promise2, x, resolve, reject)
                    } catch (e) {
                        reject(e)
                    }
                }, 0)
            }
            if (this.status === PENDING) {
                this.onResolvedCallbacks.push(() => {
                    // 用 setTimeout 模拟异步
                    setTimeout(() => {
                        try {
                            const x = onFulfilled(this.value)
                            resolvePromise(promise2, x, resolve, reject)
                        } catch (e) {
                            reject(e)
                        }
                    }, 0)
                })
                this.onRejectedCallbacks.push(() => {
                    // 用 setTimeout 模拟异步
                    setTimeout(() => {
                        try {
                            const x = onRejected(this.reason)
                            resolvePromise(promise2, x, resolve, reject)
                        } catch (e) {
                            reject(e)
                        }
                    }, 0)


                })
            }
        })

        return promise2
    }
    // catch函数实际上里面就是调用了then方法
    catch (errCallback) {
        return this.then(null, errCallback)
    }
}

