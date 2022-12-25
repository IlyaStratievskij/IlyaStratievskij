define(['jquery'], function($){
    var CustomWidget = function () {
    	var self = this;

		this.callbacks = {
			render: function(){
				console.log('render');
				return true;
			},
			init: function(){

				console.log('init');

				AMOCRM.addNotificationCallback('widget_code', function (data) {
					console.log(data)
				});

				return true;
			},
			bind_actions: function(){
				console.log('bind_actions');
				return true;
			},
			settings: function(){
				return true;
			},
			onSave: function(){
				alert('click');
				return true;
			},
			destroy: function(){

			},
			contacts: {
					//выберите контакты в списке и нажмите на название виджета

          selected: function(){
            var c_data = self.list_selected().selected;
            console.log(c_data);
            var scriptURL = 'https://script.google.com/home/projects/1sRaA9SC4yzLEoeAzvKiuOvAYcVNuJjVKTfS9VEArBjLsxIL5s78DcMvE/edit';
            body = new FormData();
            body.append("email", c_data[0].emails[0]);
            body.append("id", c_data[0].id);
            body.append("phone", c_data[0].phones[0]);
            for (var p of body) {
              let name = p[0];
              let value = p[1];

              console.log(name, value)
            }

            $.ajax({
              url: scriptURL,
              data: body,
              processData: false,
              contentType: false,
              type: 'POST',
              success: function(data){
                console.log(data);
              }
            })


						console.log('contacts');
					}
				},
			leads: {
					//выберите потенциальных клиентов в списке и нажмите на название виджета
					selected: function(){
						console.log('leads');
					}
				},
			tasks: {
					//выберите задачи в списке и нажмите на название виджета
					selected: function(){
						console.log('tasks');
					}
				}
		};
		return this;
    };

return CustomWidget;
});
