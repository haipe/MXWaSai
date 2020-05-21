// pages/home/home.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
      joke_detail:''
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.onNew()
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  },
  onNew: function() {
    wx.request({
      url: 'https://www.mxnzp.com/api/jokes/list/random',
      header: {
        app_id:'jvnrxksaljmmfwmr',
        app_secret:'YTQ1dmpweGF6TVdhQnBMSjJWdnBtdz09'
      },
      success: res => {
        //console.log(res.data)
        this.setData({
          //第一个data为固定用法
          joke_detail: res.data.data[0].content
        })
       }
    })
  }
})