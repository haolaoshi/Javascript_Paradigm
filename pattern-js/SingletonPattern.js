/**Basic Singleton **/
var Singleton = {
	attr1	: true,
	attr2	: 0,
	method1	:	function () {
		
	},
	method2	:	function () {
		
	}
};

Singleton.attr1 = false;
var total = Singleton.attr2 + 5;
var result = Singleton.method1();

//this violate one of Dsign priciples : class should open to extension but closed for modification.
//This isn't to worry about in Javascript . If you do need , you can define them use enclosue.

//Namespace
var GiantCorp = window.GiantCorp || {};  //assuming GiantCorp namespace have already have been created.

GiantCorp.Common = {
//a singleton with common methods
};
GiantCorp.ErroCodes = {
//a object literal store data
};
GiantCorp.PageHandler = {
	//a singleton with page specific methods and attribute
};

//As a Page Wrapper
Namespace.PageName = {
	//constance
	CONSTANCE_ONE	:	true,
	CONSTANCE_TWO	:	2,

	//page method
	method1	:	function () {

	},
	method2	:	function () {

	},
	//initialize
	init	:		function () {

	}
};

addLoadEvent(Namespace.PageName.init());

//--------------------------------------------------------
GiantCorp.RegPage = {
	//Constants:
	FORM_ID	:	'reg-form',
	OUTPUT_ID	:	'reg-results',

	handleSubmit	:	function (e) {
		e.preventDefault();//Stop normal form subission
		var data = {};
		var inputs = GiantCorp.RegPage.formE1.getElementByTagName('input');
		for(var i =0 , len = input.length; i<len; i++){
			data[inputs[i].name] = inputs[i].name;
		}
		GiantCorp.RegPage.sendRigistration(data);
	},
	sendRegistration	:	function (data) {
		//Make XHR request and call displayResult ....
	},
	displayResult	:	function (response) {
		GiantCorp.RegPage.outputE1.innerHTML = response.text;
	},
	init	:	function () {
		GiantCorp.RegPage.formE1 = $(GiantCorp.RegPage.FORM_ID);
		GiantCorp.RegPage.outputE1 = $(GiantCorp.RegPage.OUTPUT_ID);

		//Hijack the form submission
		addEvent(GiantCorp.RegPage.formE1, 'submit', GiantCorp.RegPage.handleSubmit);
	}
};

addLoadEvent(GiantCorp.RegPage.init);

//////////////////////////////////////////////// a singleton with private members
/*** 1) using underScore **/
GiantCorp.DataParser = {
	//private
	_stripeWhiteSpace	:	function (str) {
		return str.replace(/\s+/,'');
	},
	_stripteSplit	:	function (str,delemiter) {
		return str.split(delemiter);
	},

	//public
	stringToArray	:	function (str,delimiter,stripWS) {
		if(stripWS){
			str = this._stripeWhiteSpace(str);
		}
		var outArray = this._stripteSplit(str,delimiter);
		return outArray;
	}
};
/*** 2) Using closure  **/
//VERSION_0.1
MyNameSpace.Singleton = {};
//VERSION_0.2
MyNameSpace.Singleton = function () {
	return {}
}();

//Singleton with private members
MyNameSpace.Singleton = (function () {
	return {};
})();

MyNameSpace.Singleton = (function () {
	return {
		//public members
		publicAttr1	:	true,
		publicAttr2	:	10,

		publicMethod	:	function () {
			
		},
		publicMethod2	:	function () {
			
		}
	};
})();

MyNameSpace.Singleton = (function () {
	//Private members
	var privateAttr1	= false;
	var privateAttr2	= [1,2,3];
	function privateMethod1() {
		
	}
	function privateMethod2() {

	}
	return {//public members
		publicAttr1	:	true,
		publicAttr2	:	10,
		publicMethod1	:	function () {
			
		},
		publicMethod2	:	function () {
			
		}
	};
})();

/**
 Using true private method
 **/

GiantCorp.DataParser = (function () {
	//private
	var whiteSpace = /\s+/;
	//private
	function stripeWhitespace(str) {
		return str.replace(whiteSpace);
	}
	function stringSplit(str,delimiter) {
		return str.split(delimiter);
	}

	return {
		//public
		stringToArray	:	function (str,delimiter,stripWS) {
			if(stripWS){
				str = stripeWhitespace(str);
			}
			var outputStr = stringSplit(str,delimiter);
			return outputStr;
		}
	};
})();
//
//----------------    all mentioned before are eager type singleton  , now we discuss lazy-type singleton  -------//
// the difference is call static method as  getinstace() now,

MyNameSpace.Singleton = (function () {
	var uniqueSingle;
	function constructor() {

	};
	return {
		getInstance	:	function () {
			if(!uniqueSingle){
				uniqueSingle = constructor();
			}
			return uniqueSingle;
		}
	}
})();

APhonebar.acceptId = (function () {
	var uniqueAcceptId;
	function addAcceptInfo(name,phone,agent) {
		var params = [name,phone,agent];
		var callback = {
			success	:	function () {
				return acceptId;
			},
			faied		:	function () {
				alert('no previleged!');
			}
		};
		Ajax('request add phoneService',true,callback);
	}
	return {
		getInstance	:	function () {
			if(!uniqueAcceptId){
				uniqueAcceptId = addAcceptInfo(name,phone,agent);
			}
			return uniqueAcceptId;
		}
	};
})();


/////Branching technology
MyNameSpace.Singleton = (function () {
	var objA = {
		method1	:	function () {

		},
		method2 : function () {

		}
	};
	var objB = {
		method1	:	function () {

		},
		method2	:	function () {

		}
	};
	return (someCondition ) ? objA : objB;
})();
